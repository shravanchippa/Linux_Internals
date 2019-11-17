usb-gadget driver example
  dummy_hcd.c
    The dummy_hcd driver simulates a host-to-peripheral USB link within one
    kernel; it can be a huge help when developing new gadget drivers.

  zero.c
    Gadget Zero is essential for controller driver testing. It provides
    two configurations: one for bulk traffic source/sink, and another for
    bulk traffic loopback. On the device side it helps verify that the
    driver stack pass USB-IF and other tests (needed for at least USB
    branding). On the host side it helps test the USB stack, such as the
    Linux-USB HCDs and usbcore.

    Use it with the Linux host/master side "usbtest" driver to get a basic
    functional test of your device-side usb stack, or with "usb-skeleton".

  insmod dummy_hcd.ko
  insmod g_zero.ko
  insmod usbtest.ko or usb-skeleton.ko

