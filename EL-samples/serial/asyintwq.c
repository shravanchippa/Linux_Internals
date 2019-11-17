/************************************************************************/
/*  program for tx/rx through interrupt (Linux)                         */
/*  File Name  : asyint.c						*/
/*  Written By : B R Sahu						*/
/*  Description:							*/
/*      Transmit/receive characters through interrupt (use COM1)  	*/
/*  Note: runs on Linux Kernel 2.6                                      */
/*  Created on:27/08/05				 updated on: 14/04/07  	*/
/************************************************************************/

/*                      include                                 */

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/delay.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

/*                      constants                               */

#define P_ASY0	   0x03F8	/* base address of COM1 */
#define irq	   0x04		/* IRQ 4 */

#define RS232_BASE P_ASY0	/* select COM1 */
#define RXDAT	   0		/* Receive Data reg */
#define TXDAT      0		/* Transmit data reg */
#define INTEN      1		/* Intr. enable reg */
#define IIR	   2		/* interrupt identfier register */
#define LINECTR    3		/* line control reg */
#define MODCTR     4		/* modem control reg */
#define LINESTAT   5		/* line status reg */
#define DIVDATLO   0		/* Baud rate Lo byte */
#define DIVDATHI   1		/* baud rate Hi byte */

/*                      Global variables                        */

char rxbuf[1024];		/* ring buffer */
char *p_rxhd,*p_rxtl;		/* head ptr, tail ptr */

static struct work_struct short_wq;

void short_do_tasklet(void)
{
  printk("In work queue\n");
}


/* Receive interrupt service for COM1 */
int interrupt_handler(int i,void *v, struct pt_regs *pt_reg)
{
      *p_rxhd++ = inb(RS232_BASE+RXDAT);
      if (p_rxhd >= rxbuf+1024)
	p_rxhd = rxbuf;
      schedule_work(&short_wq);
      return IRQ_HANDLED;
}    
/* intialize com1/com2 port */
int init8250(void)
{

   outb(0x80, RS232_BASE+LINECTR);	/* enable DLAB bit */
   outb(0x00, RS232_BASE+DIVDATHI);	/*           HI byte of divisor */
   outb(0x06, RS232_BASE+DIVDATLO);	/* 192000 Baud, LO byte of divisor */
   outb(0x03, RS232_BASE+LINECTR);	/* 8bit data, 1 stop, no parity */

   outb(1, RS232_BASE+INTEN);		/* enable rx data interrupt */
   outb(0x0b, RS232_BASE+MODCTR);	/* set out2 = 0 to enable hwint */
   inb(RS232_BASE+RXDAT);		/* read the char and discard it */

   return 0;
}
/* initialize com1/com2 buffer ptrs, int vector address */
int initcom(void)
{
    int sts;
    /* set buffer address, head ptr and tail ptr */
    p_rxhd = rxbuf;
    p_rxtl = rxbuf;
    init8250();
    sts = request_irq(irq,interrupt_handler,SA_INTERRUPT,"mydevice",NULL);
    if (sts < 0)
    {
        printk("<1> PANIC !!! NOT ABLE TO GET IRQ\n");
    }
   
    return 0;
}
/* restore interrupt vector and disbale intr */
int rescom(void)
{
   /* disable 8250 int */
   outb(0, RS232_BASE+INTEN);
   free_irq(irq,NULL);

   return 0;
}
/* get a character from comm. buffer */
int rcv_chr(void)
{
   int ch;
   if (p_rxhd == p_rxtl)
      return(-1);
   ch = *p_rxtl++;
   if (p_rxtl >= rxbuf+1024)
      p_rxtl = rxbuf;
   return(ch);
}
/* put a char on COM2 port */
int tx_chr(unsigned int ch)
{
   unsigned char stat;
   do {
	stat = inb(RS232_BASE+LINESTAT);/* read status port */
   }while ((stat & 0x20) == 0);	/* check for tx empty, if not wait */
   
   outb(ch, RS232_BASE+TXDAT);

   return 0;
}

/* start of async driver test program */
int serial_init(void)
{
   int i,c;

   printk("Module initialized\n");

   INIT_WORK(&short_wq, (void (*) (void *))short_do_tasklet, NULL);

   initcom();

   /* send a char */
   for (i = 0; i < 4; i++)
   {
     tx_chr('A'+i);

     udelay(600);
     /* process char from com. line */
     c = rcv_chr();
     printk("%c\n", c);
   }

   return 0;
}

void serial_exit(void)
{
    printk("Module removed\n");
    rescom();
}

module_init(serial_init);
module_exit(serial_exit);

