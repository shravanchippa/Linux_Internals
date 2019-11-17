/*
 * Program demonstrating modules
*/

#include <linux/module.h>

int init_module()                  //module entry point 
{
  printk(KERN_DEBUG "Module Initialized\n");  //kernel print function
  return 0;  
}

void cleanup_module()              //clean up 
{
  printk(KERN_DEBUG "Module removed\n");
}

MODULE_LICENSE("GPL");
