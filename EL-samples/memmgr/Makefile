KERNEL_BUILD := /lib/modules/`uname -r`/build
CC := gcc
obj-m := kmalloc.o
modules:
	@$(MAKE) -C $(KERNEL_BUILD) M=$(PWD) $@

