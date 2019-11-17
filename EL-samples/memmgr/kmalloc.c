/*
 * Progarm demonstrating the use of kmalloc
*/
 
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");

void *memptr;                                      //memory pointer

int kmalloc_init()
{
  size_t size = 1024;                              //allocate 1024 bytes
  memptr = (void *) kmalloc(size,0);               //in the kernel segment 
  if(memptr == (void *) 0)
    {
    printk("Dynamic memory allocation failed\n");
    return -1;
    }
  else
    printk("Memory allocated successfully\n");
  printk("KLA %x\n", memptr);
  return 0;
 }

void kmalloc_exit()
{
  kfree(memptr);                                   //free the allocated memory 
  printk("Memory deallocated\n");
} 

module_init(kmalloc_init);
module_exit(kmalloc_exit);

