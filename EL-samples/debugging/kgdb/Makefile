KERNEL_BUILD := /lib/modules/`uname -r`/build
CC := gcc
PROG := ioctltst
obj-m := ioctl.o

modules:
	@$(MAKE) -C $(KERNEL_BUILD) M=$(PWD) $@

$(PROG): $(PROG).c
	@$(CC) -o $(PROG) $(PROG).c
