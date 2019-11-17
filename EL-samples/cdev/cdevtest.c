/*
 * application program to test driver sample 4
 */
char device[] = {"/dev/mydevice"};

main()
{
   int fd, nb;
   char wbuff[32];
   char rbuff[32];

   fd = open(device, 0666);
   if (fd <= 0)
   {
     err_sys("Can not open the device\n");
   }
   nb = write(fd, wbuff, 16);
   if (nb != 16)
     err_sys("Write Error\n");
   printf("No. of Bytes Written = %d\n", nb);
   nb = read(fd, rbuff, 16);
   printf("No. of Bytes Read = %d\n", nb);
   close(fd);
   exit(0);
}

/* display err message and exit */

err_sys(char *s)
{
  printf("%s\n", s);
  exit(1);
}

