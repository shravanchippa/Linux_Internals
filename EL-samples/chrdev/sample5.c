/*
 * Interrupt Request
*/


#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/interrupt.h>

#define MY_MAJOR	250

int major;
short int irq;

struct file_operations my_fops;

void interrupt_handler(int i,void *v, struct pt_regs *pt_reg)
{
}

int my_init(void)
{
        int sts;
	irq=7;
        printk("<1>Hello World\n");
        major = register_chrdev(MY_MAJOR,"mydevice",&my_fops);

        sts = request_irq(irq,interrupt_handler,SA_INTERRUPT,"mydevice",NULL);
        if (sts < 0)
	{
              printk("<1> PANIC !!! NOT ABLE TO GET IRQ\n");
        }

        return 0;
}

void my_cleanup(void)
{
        printk("<1> Goodbye\n");
        free_irq(irq,NULL);
        unregister_chrdev(MY_MAJOR,"mydevice");
}

module_init(my_init);
module_exit(my_cleanup);

MODULE_LICENSE("GPL");

