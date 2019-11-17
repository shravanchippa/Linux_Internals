/*
 * find and extract PCI configuration and read MAC address
 * loopback test using PCI DMA kernel functions 
 * for pcnet (AMD chip)
 * B R Sahu, 29/05/09
*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <asm/dma.h>

/* PCI configuration space */

#define VENDOR_ID               0x1022 
#define DEVICE_ID               0x2000

/* Device (Am79C973) Registers */
#define RDP		0x10		/* Register Data Port */
#define RAP		0x12		/* Register Address Port */
#define RESET		0x14		/* Reset Register */
#define BDP		0x16		/* BCR Data Port */

#define CSR0		0		/* controller status and control reg */
#define CSR1		1		/* initialization block address 0 */
#define CSR2		2		/* initialization block address 1 */
#define CSR12		12		/* Physical Address Reg 0 */
#define CSR13		13		/* Physical Address Reg 1 */
#define CSR14		14		/* Physical Address Reg 2 */
#define CSR15		15		/* Mode register */

#define BCR20		20		/* Software style register */
#define BCR32		32		/* PHY control and status register */

struct pci_dev *pdev;			/* PCI device structure */
unsigned long IOBase, IOBaseEnd;
unsigned long ulMemoryBase, ulMemoryBaseEnd;
unsigned long ulResFlags;
unsigned char dev_addr[6];		/* holds MAC address */

/* The PCNET32 32-Bit initialization block, described in databook. */
struct pcnet32_init_block {
        u16     mode;
        u16     tlen_rlen;
        u8      phys_addr[6]; 
        u16     reserved;
        u32     filter[2];
        /* Receive and transmit ring base, along with extra bits. */
        u32     rx_ring;
        u32     tx_ring;
} *init_block;

/* The PCNET32 Rx and Tx ring descriptors. */
struct pcnet32_rx_head {
        u32     base;
        s16     buf_length;     /* two`s complement of length */
        u16     status;
        u32     msg_length;
        u32     reserved;
} *rx_ring;

struct pcnet32_tx_head {
        u32     base;
        s16     length;         /* two`s complement of length */
        u16     status;
        u32     misc;
        u32     reserved;
} *tx_ring;

dma_addr_t init_dma_addr;	/* DMA address of beginning of the init block,
                                   returned by pci_alloc_consistent */
dma_addr_t     rx_ring_dma_addr;
dma_addr_t     tx_ring_dma_addr;
unsigned short rx_len_bits;
unsigned short tx_len_bits;
unsigned short tx_ring_size = 1;
unsigned short rx_ring_size = 1;
dma_addr_t     *tx_dma_addr;
dma_addr_t     *rx_dma_addr;

/* loopback test - internal */
int loopback_test(void)
{
  unsigned short status;
  int i;
  unsigned char *tpacket;
  unsigned char *rpacket;
  unsigned char *tptr;
  unsigned char *rptr;

  printk("\nLoopback Test...\n");

  /* switch to 32 bit mode */
  outw(BCR20, IOBase + RAP);
  outw(0x02, IOBase + BDP);

  /* pci_alloc_consistent returns page-aligned memory, 
     so we do not have to check the alignment */
  if ((init_block =
    pci_alloc_consistent(pdev, sizeof(*init_block), &init_dma_addr)) == NULL) {
      printk(KERN_ERR "Consistent memory allocation failed.\n");
      return -ENOMEM;
  }

  tx_ring = pci_alloc_consistent(pdev,
                                 sizeof(struct pcnet32_tx_head) *
                                 tx_ring_size,
                                 &tx_ring_dma_addr);
  if (tx_ring == NULL) {
      printk(KERN_ERR "tx_ring allocation failed.\n");
      pci_free_consistent(pdev, sizeof(*init_block), init_block, init_dma_addr);
      return -ENOMEM;
  }

  rx_ring = pci_alloc_consistent(pdev,
                                 sizeof(struct pcnet32_rx_head) *
                                 rx_ring_size,
                                 &rx_ring_dma_addr);
  if (tx_ring == NULL) {
      printk(KERN_ERR "rx_ring allocation failed.\n");
      pci_free_consistent(pdev, sizeof(*init_block), init_block, init_dma_addr);
      pci_free_consistent(pdev, sizeof(struct pcnet32_tx_head), tx_ring, tx_ring_dma_addr);
      return -ENOMEM;
  }

  tpacket = kmalloc(1024, GFP_KERNEL);
  if (tpacket == NULL) {
      printk(KERN_ERR "packet allocation failed.\n");
  }
  tx_dma_addr = pci_map_single(pdev, tpacket, 1024, PCI_DMA_TODEVICE);
  tx_ring->base = le32_to_cpu(tx_dma_addr);

  rpacket = kmalloc(1024, GFP_KERNEL);
  if (rpacket == NULL) {
      printk(KERN_ERR "packet allocation failed.\n");
  }
  rx_dma_addr = pci_map_single(pdev, rpacket, 1024, PCI_DMA_FROMDEVICE);
  rx_ring->base = le32_to_cpu(rx_dma_addr);
  rx_ring->buf_length = le16_to_cpu(-1024);	/* two's complement */
  rx_ring->status = le16_to_cpu(0x8000);

  /* fill up the initialization block structure */
  init_block->mode = le16_to_cpu(0x0003);     /* Disable Rx and Tx. */
  tx_len_bits = 1 << 12;
  rx_len_bits = 1 << 4;
  init_block->tlen_rlen = le16_to_cpu(tx_len_bits | rx_len_bits);
  for (i = 0; i < 6; i++)
    init_block->phys_addr[i] = dev_addr[i];
  init_block->filter[0] = 0x00000000;
  init_block->filter[1] = 0x00000000;
  init_block->rx_ring = (u32) le32_to_cpu(rx_ring_dma_addr);
  init_block->tx_ring = (u32) le32_to_cpu(tx_ring_dma_addr);

  outw(CSR1, IOBase + RAP);
  outw(init_dma_addr & 0xffff, IOBase + RDP);
  outw(CSR2, IOBase + RAP);
  outw(init_dma_addr >> 16, IOBase + RDP);
  outw(CSR0, IOBase + RAP);
  outw(1, IOBase + RDP);	/* trigger initialization */

  udelay(100);			/* let init get complete */
  outw(CSR0, IOBase + RAP);
  status = inw(IOBase + RDP);
  printk("INIT Status: %04x\n", status);

  /* fill data */
  tptr = tpacket;
  for (i = 0; i < 6; i++)	/* DA */
    *tptr++ = dev_addr[i];
  for (i = 0; i < 6; i++)	/* SA */
    *tptr++ = dev_addr[i];
  *tptr++ = 0x08;		/* Frame Type */
  *tptr++ = 0x06;
  for (i = 0; i < 16; i++)	/* arbitrary data */
    *tptr++ = 'A'+i;

  tx_ring->length = le16_to_cpu(-128);	/* two's complement */
  tx_ring->status = le16_to_cpu(0x8300);
  tx_ring->misc = 0;
 
  /* set internal loop back */
  outw(BCR32, IOBase + RAP);
  status = inw(IOBase + BDP);
  outw(status | 0x02, IOBase + BDP);   /* MII internal loop back, Bit 1 */

  outw(CSR15, IOBase + RAP);
  status = inw(IOBase + RDP) & 0xfffc;
  outw(status | 0x44, IOBase + RDP);   /* CSR15, bit 6(INTL), bit 2 (LOOP) */

  outw(CSR0, IOBase + RAP);
  outw(0x02, IOBase + RDP);   		/* set STRT bit 1 */

  mdelay(100);				/* let tx and rx get complete */

  printk("tx status  : %04x\n", tx_ring->status);
  printk("rx status  : %04x\n", rx_ring->status);

  /* display received data */
  rptr = rpacket;
  for (i = 0; i < 24; i++)
    printk("%02x ", *rptr++);
  printk("\n");

  outw(CSR0, IOBase + RAP);
  outw(0x04, IOBase + RDP);            /* set STOP bit 2 */
  
  printk("Loopback Test Done...\n");

  /* free the resources */
  kfree(tpacket);
  kfree(rpacket);

  pci_free_consistent(pdev, sizeof(*init_block), init_block, init_dma_addr);
  pci_free_consistent(pdev, sizeof(struct pcnet32_tx_head), tx_ring, tx_ring_dma_addr);
  pci_free_consistent(pdev, sizeof(struct pcnet32_rx_head), rx_ring, rx_ring_dma_addr);

  return 0;
}

/* Read MAC address through I/O Registers */
void ReadMACAddrIORegisters(void)
{
  unsigned short status;
  int i;

  printk("\n*** MAC Address thru I/O Mapped Registers ***\n");

  /* reset the chip */
  inw(IOBase + RESET);

  /* read MAC address */
  for (i = 0; i < 3; i++)
  {
    outw(CSR12+i, IOBase + RAP);
    udelay(100);
    status = inw(IOBase + RDP);
    dev_addr[i*2] = status & 0xff;
    dev_addr[i*2+1] = status >> 8;
  }
  for (i = 0; i < 6; i++)
    printk("MAC Addr[%d] Value = %02x\n", i, dev_addr[i]);
}

/* read the configuration space and extract BARs */
int get_card_details(void)
{
  unsigned char cIntLine;

  printk("\n*** PCI Device Registers ***\n");

  pdev = pci_find_device(VENDOR_ID,DEVICE_ID,0);
  if (pdev == 0)
  {
    printk("Device not found\n");
    return -1;
  }
  else
  {
    printk("Device found\n");

    ulMemoryBase = pci_resource_start( (struct pci_dev *)pdev, 1);

    ulMemoryBaseEnd = pci_resource_end( (struct pci_dev *)pdev, 1);

    ulResFlags = pci_resource_flags( (struct pci_dev *)pdev, 1);

    if (ulResFlags & IORESOURCE_MEM)
      printk("BAR1 Memory Mapped Base Address is: %08lx End %08lx\n",
			ulMemoryBase, ulMemoryBaseEnd);

    IOBase = pci_resource_start( (struct pci_dev *)pdev, 0);

    IOBaseEnd = pci_resource_end( (struct pci_dev *)pdev, 0);

    ulResFlags = pci_resource_flags( (struct pci_dev *)pdev, 0);

    if (ulResFlags & IORESOURCE_IO)
      printk("BAR0 I/O Mapped Base Address is: %08lx End %08lx\n",
			IOBase, IOBaseEnd);

    pci_read_config_byte( (struct pci_dev *)pdev,
				PCI_INTERRUPT_LINE, &cIntLine);
    printk("IRQ Used is: %02x \n", cIntLine);

    pci_enable_device(pdev);

    return 0;
  }
}

/* initialization */

int nic_init(void)
{
  int res;

  printk("Module Initialized\n");

  res = get_card_details();
  if (res == 0)
  {
    ReadMACAddrIORegisters();

    loopback_test();
  }

  return res;  
}

/* cleanup */

void nic_exit(void)
{
  printk("Module removed\n");
}

module_init(nic_init);
module_exit(nic_exit);

MODULE_LICENSE("GPL");

