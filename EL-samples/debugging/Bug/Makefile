KERNEL_BUILD := /lib/modules/`uname -r`/build
CC := gcc
obj-m := bugon.o
modules:
	@$(MAKE) -C $(KERNEL_BUILD) M=$(PWD) $@

