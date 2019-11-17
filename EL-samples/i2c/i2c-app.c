/*
 * access an i2c adapter from user space program
 * gcc -o i2c-app i2c-app.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <asm/types.h>

#include "i2c-dev.h"

int main()
{
  int file;
  int adapter_nr = 0; /* probably dynamically determined */
  char filename[20];
  __u8 reg = 0x00;    /* Device register to access */
  __s32 res;
  char buf[10];

  sprintf(filename,"/dev/i2c-%d",adapter_nr);
  if ((file = open(filename,O_RDWR)) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    perror("i2c-app@open");
    exit(1);
  }

  int addr = 0x20; /* The I2C address */
//  if (ioctl(file,I2C_SLAVE,addr) < 0) {
  if (ioctl(file,I2C_SLAVE_FORCE,addr) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    perror("i2c-app@ioctl");
    exit(1);
  }

  /* Using SMBus commands */
  res = i2c_smbus_write_byte_data(file,reg, 0x01);
  if (res < 0) {
    /* ERROR HANDLING: i2c transaction failed */
    perror("i2c-app@i2c_smbus_write_byte_data");
  } else {
    res = i2c_smbus_read_byte_data(file, reg);
    /* res contains the read byte */
    printf("value = %02x\n", res);
  }

  close(file);
  exit(0);
}

