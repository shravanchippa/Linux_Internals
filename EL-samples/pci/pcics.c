/*
 * find and extract PCI configuration for NIC
 * gcc -O2 -c pcics.c (short)
 * gcc -O2 -c pcics.c -nostdinc -I/usr/src/linux-2.4.18-14/include -I/usr/lib/gcc-lib/i386-redhat-linux/3.2/include (long)
*/

#include <linux/module.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <asm/io.h>

/* PCI configuration space */

#define VENDOR_ID               0x8086 
#define DEVICE_ID               0x1039
#define PCI_MEMORY_OFFSET       0x10
#define PCI_IO_OFFSET           0x14
#define PCI_IRQ_OFFSET          0x3C

/* Intel Ether Pro/100 VE specific */
#define MDICR		0x10	/* Media Data Interface control Register */

unsigned short IOBase;
unsigned int ulMemoryBase;

/* read the configuration space and extract BARs */
int get_card_details()
{
  unsigned int ulIOBase;
  unsigned char cIntLine;
  struct pci_dev *pdev;

  printk("\n*** PCI Device Registers ***\n");

  if (pci_present())
     printk("PCI Present\n");
  else
  {
     printk("PCI Not Present\n");
     return -1;
  }

  pdev = pci_find_device(VENDOR_ID,DEVICE_ID,0);
  if (pdev == 0)
  {
     printk("Device not found\n");
     return -1;
  }
  else
  {
    printk("Device found\n");

    pci_read_config_dword((struct pci_dev *) pdev,
				PCI_MEMORY_OFFSET, &ulMemoryBase);
    printk("CSR Memory Mapped Base Address is: %lx\n", ulMemoryBase);

    pci_read_config_dword( (struct pci_dev *)pdev,
				PCI_IO_OFFSET, &ulIOBase);
    ulIOBase &= 0xfffe;    	// mask the rightmost bit
    IOBase = ulIOBase;

    printk("CSR I/O Mapped Base Address is: %04x\n", IOBase);

    pci_read_config_byte( (struct pci_dev *) pdev,
				PCI_IRQ_OFFSET, &cIntLine);
    printk("IRQ Used is: %02x \n", cIntLine);

    return 0;
  }
}

/* Read Registers (Identification) */
void ReadRegisters()
{
  unsigned short status;

  printk("\n*** MDI Registers thru I/O Mapped ***\n");

//Read Register 1 (expected value 782d or 7809 (cable removed))
  outl(0x08210000, IOBase + MDICR);
  udelay(100);
  status = inl(IOBase + MDICR);
  printk("MDI Reg1 Value = %04x\n", status);

//Read Register 2 (expected value = 02A8)
  outl(0x08220000, IOBase + MDICR);
  udelay(100);
  status = inl(IOBase + MDICR);
  printk("MDI Reg2 Value = %04x\n", status);

//Read Register 3 (expected value = 0330)
  outl(0x08230000, IOBase + MDICR);
  udelay(100);
  status = inl(IOBase + MDICR);
  printk("MDI Reg3 Value = %04x\n", status);
}
/* Read Memory Mapped I/O - MDI Registers */
void MemIORegisters()
{
  unsigned short status;
  unsigned long MemBase;

  printk("\n*** MDI Registers thru Mem Mapped ***\n");

  MemBase = (unsigned long)ioremap(ulMemoryBase, 4096);

//Read Register 1 (expected value 782d or 7809 (cable removed))
  writel(0x08210000, MemBase + MDICR);
  udelay(100);
  status = readl(MemBase + MDICR);
  printk("MDI Reg1 Value = %04x\n", status);

//Read Register 2 (expected value = 02A8)
  writel(0x08220000, MemBase + MDICR);
  udelay(100);
  status = readl(MemBase + MDICR);
  printk("MDI Reg2 Value = %04x\n", status);

//Read Register 3 (expected value = 0330)
  writel(0x08230000, MemBase + MDICR);
  udelay(100);
  status = readl(MemBase + MDICR);
  printk("MDI Reg3 Value = %04x\n", status);

  iounmap((void *)MemBase);
}

/* initialization */

int pcics_init()
{
  int res;

  printk("Module Initialized\n");

  res = get_card_details();
  if (res == 0)
  {
    ReadRegisters();

    MemIORegisters();

    return 0;
  }else
	  return -1;
}

/* cleanup */

void pcics_exit()
{
  printk("Module removed\n");
}

module_init(pcics_init);
module_exit(pcics_exit);

MODULE_LICENSE("GPL");

