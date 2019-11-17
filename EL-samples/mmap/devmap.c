/*
 * find and extract PCI configuration for NIC (RTL8139)
 * make -C /usr/src/kernels/2.6.x M=`pwd` modules
 * Note: runs on Linux Kernel 2.6
 * Modified on 14/04/07 
*/

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <asm/io.h>

/* PCI configuration space */

#define VENDOR_ID		0x10ec 
#define DEVICE_ID         	0x8139
#define PCI_IO_OFFSET     	0x10
#define PCI_MEMORY_OFFSET 	0x14
#define PCI_IRQ_OFFSET    	0x3C

#define MY_MAJOR		250

int major, ret_val;
unsigned short IOBase;
unsigned int ulMemoryBase;

/* read the configuration space and extract BARs */
int get_card_details()
{
  unsigned int ulIOBase;
  unsigned char cIntLine;
  struct pci_dev *pdev;

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


void simple_vma_open(struct vm_area_struct *vma)
{

    printk(KERN_NOTICE "Simple VMA open, virt %lx, phys %lx\n",

            vma->vm_start, vma->vm_pgoff << PAGE_SHIFT);

}


void simple_vma_close(struct vm_area_struct *vma)
{

    printk(KERN_NOTICE "Simple VMA close.\n");

}


static struct vm_operations_struct simple_remap_vm_ops = {

    .open =  simple_vma_open,

    .close = simple_vma_close,

};

static int my_mmap(struct file *filp, struct vm_area_struct *vma)
{
    unsigned long offset;

    printk("my mmap %x %x\n", vma->vm_start, vma->vm_end);
    offset = vma ->vm_pgoff << PAGE_SHIFT;
    if (remap_page_range(vma->vm_start, offset,
                vma->vm_end - vma->vm_start,
                vma->vm_page_prot))
        return -EAGAIN;
    printk("map offset %x\n", offset);

    vma->vm_ops = &simple_remap_vm_ops;
//    simple_vma_open(vma);

    return 0;

}

/************************************************************************************
****	When application calls int open(const char *pathname, int flags),	 ****
****	my_open() method will be invoked by the Kernel, which returns		 ****
****	the file descriptor for the device or -1 if any error occurs		 ****
************************************************************************************/

static int my_open(struct inode *inode, struct file *filp)
{
      int minor;
      minor = MINOR(filp->f_dentry->d_inode->i_rdev);
      printk("\n*****Some body is opening me at minor %d*****\n",minor);
      return 0;
}

/************************************************************************************
****	When application calls int close(int fd), where fd is the file		 ****
****	descriptor returned by corresponding open(),				 ****
****	my_open() method will be invoked by the Kernel, which returns		 ****
****	0 on success and -1 on error						 ****
************************************************************************************/

static int my_close(struct inode *inode, struct file *filp)
{
    int minor;
    minor = MINOR(filp->f_dentry->d_inode->i_rdev);
    printk("*****Some body is closing me at minor %d*****\n",minor);
    return 0;
}


/************************************************************************************
****	When application calls ssize_t read(int fd, void *buf, size_t count),	 ****
****	where fd is the file descriptor returned by corresponding open(),	 ****
****	buf is user buffer, and count is the number of bytes requested,		 ****
****	my_read() method will be invoked by the Kernel, which returns	         ****
****	number of bytes actually transferred or -1 on error			 ****
************************************************************************************/


ssize_t my_read(struct file *filp, char *buf, size_t count, loff_t *offset)
{
    int minor;
    minor = MINOR(filp->f_dentry->d_inode->i_rdev);
    printk("*****Some body is reading me at minor %d*****\n",minor);

    return count;
}

/************************************************************************************
****	When application calls ssize_t write(int fd, const void *buf, size_t count),*
****	where fd is the file descriptor returned by corresponding open(),	 ****
****	buf is user buffer with data, and count is the number of bytes to be written,
****	my_write() method will be invoked by the Kernel, which returns	 ****
****	number of bytes actually transferred or -1 on error			 ****
************************************************************************************/

ssize_t my_write(struct file *filp, const char *buf, size_t count, loff_t *offset)
{
    int minor;
    minor = MINOR(filp->f_dentry->d_inode->i_rdev);
    printk("*****Some body is writing me at minor*****\n",minor);
    return count;
}

/************************************************************************************
****	When application calls int ioctl(int fd, int request char *argp),        ****
****	where fd is the file descriptor returned by corresponding open(),	 ****
****	request is command, and argp is a pointer to argument list,              ***
****	my_ioctl() method will be invoked by the Kernel, which returns	 ****
****	0 or a positive integer on success or -1 on error			 ****
************************************************************************************/

int my_control(struct inode *inode, struct file *filp, unsigned int command, unsigned long argument)
{
    int minor;
    minor = MINOR(filp->f_dentry->d_inode->i_rdev);
    printk("*****Some body is controlling me at minor %d*****\n",minor);
    return 0;
}

struct file_operations my_fops = {
        read    :       my_read,
        write   :       my_write,
        open    :       my_open,
        release :       my_close,
        ioctl   :       my_control,
	mmap    :	my_mmap,
        owner   :       THIS_MODULE,
        };


/* initialization */

int my_init()
{
  int res;

  printk("Module Initialized\n");

  major = register_chrdev(MY_MAJOR,"mydevice",&my_fops);
  res = get_card_details();
  return res;
}

/* cleanup */

void my_exit()
{
  printk("Module removed\n");
  unregister_chrdev(MY_MAJOR,"mydevice");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

