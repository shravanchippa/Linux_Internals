i2c driver example
  i2c-stub.c
    A very simple fake I2C/SMBus driver.

  i2c-app.c
    Accessing an i2c adapter from user space

  insmod i2c-dev.ko
  insmod i2c-stub.ko
  i2cdetect -l
  i2c-app or sensors-detect

