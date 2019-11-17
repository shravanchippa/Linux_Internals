/*
 * find and extract PCI configuration for NIC
 * gcc -O2 -c pcires.c (short)
 * gcc -O2 -c pcires.c -nostdinc -I/usr/src/linux-2.4.18-14/include -I/usr/lib/gcc-lib/i386-redhat-linux/3.2/include (long)
*/

#include <linux/module.h>
#include <linux/pci.h>

/* PCI configuration space */

#define VENDOR_ID               0x1022 
#define DEVICE_ID               0x2000

unsigned long IOBase, IOBaseEnd;
unsigned long ulMemoryBase, ulMemoryBaseEnd;
unsigned long ulResFlags;

/* read the configuration space and extract BARs */
int get_card_details()
{
  unsigned int ulIOBase;
  unsigned char cIntLine;
  struct pci_dev *pdev;

  printk("\n*** PCI Device Registers ***\n");
/*
  if (pci_present())
     printk("PCI Present\n");
  else
     printk("PCI Not Present\n");
*/
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
    return 0;
  }
}

/* initialization */

int nic_init()
{
  int res;

  printk("Module Initialized\n");

  res = get_card_details();

  return res;  
}

/* cleanup */

void nic_exit()
{
  printk("Module removed\n");
}

module_init(nic_init);
module_exit(nic_exit);

MODULE_LICENSE("GPL");

