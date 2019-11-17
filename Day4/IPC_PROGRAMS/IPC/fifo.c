#include <fcntl.h>

main()
{
	int fd;
	char data[40];
	
	mkfifo("hellopipe",0777);
	printf ("Fifo pipe file is created\n");
	
	fd = open("hellopipe",O_RDWR);
	
	read(fd,data,40);
	printf ("%s\n",data);
	close(fd);
}
