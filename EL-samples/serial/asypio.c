/********************************************************************/
/*		 	ASY test driver (Linux)                     */
/*      Character Tx and Rx on Serial port through PIO              */
/*      created on:27/08/05 		     updated on: 25/01/07   */
/********************************************************************/

#define  RS232_BASE 0x3f8       /* base address for Port1 */
#define  RXDAT	    0		/* Tx Data register */
#define  TXDAT      0		/* Rx Data Register */
#define  INTEN      1		/* Interrupt enable register */
#define  IIR	    2		/* interrupt identfier register */
#define  LINECTR    3		/* line control reg */
#define  MODCTR     4		/* modem control reg */
#define  LINESTAT   5		/* Line status register */
#define  DIVDATLO   0		/* Divisor Latch for Baud rate */
#define  DIVDATHI   1

#include <linux/module.h>
#include <asm/io.h>

/* Initialize COM port */
int init8250()
{
   outb(0x80, RS232_BASE+LINECTR);   /* enable DLAB bit */
   outb(0x00, RS232_BASE+DIVDATHI);  /*           HI byte of divisor  */
   outb(0x0c, RS232_BASE+DIVDATLO);  /* 9600 Baud, LO byte of divisor */
   outb(0x03, RS232_BASE+LINECTR);   /* 8bit data, 1 stop, no parity  */

   outb(0x10, RS232_BASE+MODCTR);    /* set out2 = 0 to enable hwint  */
   inb(RS232_BASE+RXDAT);            /* read the char and discard it  */
}
/* get a character from port */
int rcv_chr()
{
   unsigned char stat;
   do {
        stat = inb(RS232_BASE+LINESTAT);/* read status port */
   }while ((stat & 0x01) == 0);		/* check for rx ready, if not wait */
   
   return(inb(RS232_BASE+RXDAT));
}
/* put a char on port */
int tx_chr(unsigned int ch)
{
   int i=0;
   
   unsigned char stat;

   do {
        stat = inb(RS232_BASE+LINESTAT);/* read status port */
   }while ((stat & 0x20) == 0);	/* check for tx empty, if not wait */

   outb(ch, RS232_BASE+TXDAT);
}

int serial_init()                  //module entry point 
{
  int i, j, c;

  printk("Module Initialized\n");  //kernel print function

  /* init com port */
  init8250();

  /* send and receive characters */
 
  for (i = 0; i < 4; i++)
  {
      tx_chr(0x41+i);
      for (j = 0; j < 10000000; j++)
	  ;
      c = rcv_chr();
      printk("%c\n", c);
  }
  
  /*
  outb('A', RS232_BASE+TXDAT);
  for (i = 0; i < 10000000; i++)
	  ;
  c = inb(RS232_BASE+RXDAT);
  printk("%c\n", c);
  */
  return 0;  
}

void serial_exit()              //clean up 
{
  printk("Module removed\n");
}

module_init(serial_init);
module_exit(serial_exit);

MODULE_LICENSE("GPL");

