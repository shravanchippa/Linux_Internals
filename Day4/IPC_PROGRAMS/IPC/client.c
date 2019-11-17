#include <fcntl.h>

main(int argc,char * argv[])
{
	int fd;
	if(argc < 2)
	{
		printf ("Use 2 command line argument\n");
		exit(0);
	}

	fd  = open("hellopipe",O_RDWR);
	write(fd,argv[1],40);
	close(fd);
}
