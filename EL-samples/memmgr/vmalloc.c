/*
 * Progarm demonstrating the use of vmalloc
*/

 
#include <linux/module.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");

void *memptr;                                      //memory pointer

int vmalloc_init()
{
  unsigned long size = 5012;                       //allocate 5012 bytes
  memptr = (void *) vmalloc(size);                 //in the kernel segment 
  if(memptr == (void *) 0)
    {
    printk("Dynamic memory allocation failed\n");
    return 0;
    }
  else
    printk("Memory allocated successfully\n");
  return 0;
 }

void vmalloc_exit()
{
  vfree(memptr);                                   //free the allocated memory 
  printk("Memory deallocated\n");
} 

module_init(vmalloc_init);
module_exit(vmalloc_exit);

