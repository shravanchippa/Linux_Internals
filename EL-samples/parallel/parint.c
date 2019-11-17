/************************************************************************/
/*  program for parallel port through interrupt(Linux)                  */
/*  File Name  : parint.c						*/
/*  Written By : B R Sahu						*/
/*  Description:							*/
/*  Note: runs on Linux Kernel 2.6                                      */
/*  Created on:27/08/05				 updated on: 14/04/07 	*/
/************************************************************************/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

#define LPTBase	   0x0378	/* base address of LPT1 */

#define irq	   7		/* select IRQ 7 for LPT1 */

/* Receive interrupt service for COM1/COM2 */
int interrupt_handler(int i,void *v, struct pt_regs *pt_reg)
{
   printk("In ISR\n");
   outb(0x40, LPTBase);        /* glow LED */
   return IRQ_HANDLED;
} 

/* process function key */
int functionkey(int ch)
{
   switch (ch) {
      case '1' :		/* F1 ->    */
        outb(0x40, LPTBase);    /* make LED on */
	printk("Switch on LED\n");
	break;
      case '2' :		/* F2 ->    */
        outb(0x00, LPTBase);    /* make LED off */
	printk("Switch off LED\n");
	break;
      case '3' : 	/* F3 ->    */
        outb(0x80, LPTBase);    /* generate interrupt */
	printk("Generate Interrupt\n");
	break;
      default :
	break;
   }

   return 0;
}

/* start of parallel port test program */
int parint_init(void)
{
   int sts;

   printk("Module initialized\n");
   outb(0x00, LPTBase);

   sts = request_irq(irq,interrupt_handler,SA_INTERRUPT,"mydevice",NULL);
   if (sts < 0)
   {
        printk("<1> PANIC !!! NOT ABLE TO GET IRQ\n");
        return -1;
   }
   outb(0x10, LPTBase+2);      /* enable parallel port int */
   
   functionkey('1');
   mdelay(100);
   functionkey('2');
   mdelay(100);

   functionkey('3');
   mdelay(100);

   return 0;
}

void parint_exit(void)
{
   printk("Module removed\n");
   outb(0x00, LPTBase);
   /* disable par port int */
   outb(0x00, LPTBase+2);
   free_irq(irq,NULL);
}

module_init(parint_init);
module_exit(parint_exit);

