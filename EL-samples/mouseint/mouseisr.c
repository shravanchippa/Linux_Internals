/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                      *
* ModuleName         : mouseisr                                        *
* SourceName         : mouseisr.c                                      *
*                                                                      *
* Description        : PS/2 mouse interrrupt handler (shared mode)     *
*                                                                      *
* Programmer         : B R Sahu                                        *
* Date               : 2/1/2006                                        *
*                                                                      *
*----------------------------------------------------------------------*
* Notes:                                                               *
*      1. For compiling, Type make                                     *
*      2. For loading,   Type insmod mouseisr.ko                       *
*      3. For unloading, Type rmmod mouseisr                           *
*                                                                      *
*                                                                      *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*----------------------------------------------------------------------
 ************************** Define ********************************
 *--------------------------------------------------------------------*/

#define  MY_MAJOR       250
#define  IRQ_LINE 	12

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/ioport.h>
#include <asm/io.h>
#include <linux/interrupt.h>

/*--------------------------------------------------------------------*/

int major, ret_val;
int devid;
struct file_operations my_fops;

irqreturn_t interrupt_handler(int i,void *v, struct pt_regs *pt_reg)
{
    printk(KERN_INFO "In Interrupt Handler\n");
    return IRQ_HANDLED;
}

int my_init(void)
{
    int sts;

    printk(KERN_INFO "\nPS/2 Mouse ISR (sharing)\n");
    major = register_chrdev(MY_MAJOR,"mydevice",&my_fops);

    sts = request_irq(IRQ_LINE,interrupt_handler,SA_SHIRQ,"mydevice", &devid);
    if (sts < 0){
        printk(KERN_ERR "mouse: can not register IRQi %d\n", IRQ_LINE);
        return -EIO;
    }

    return 0;
}

void my_cleanup(void)
{
    printk(KERN_INFO "\nclean up module\n");
    free_irq(IRQ_LINE, &devid);
    unregister_chrdev(MY_MAJOR,"mydevice");
}

module_init(my_init);
module_exit(my_cleanup);

MODULE_LICENSE("GPL");

