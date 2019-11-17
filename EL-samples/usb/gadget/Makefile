#Makefile for a multi-filed module

obj-m          += dummy_hcd.o

obj-m          += g_zero.o
g_zero-objs    := zero.o usbstring.o config.o epautoconf.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

