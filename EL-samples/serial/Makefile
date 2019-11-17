KERNEL_BUILD := /lib/modules/`uname -r`/build
obj-m := asypio.o
modules:
	@$(MAKE) -C $(KERNEL_BUILD) M=$(PWD) $@

