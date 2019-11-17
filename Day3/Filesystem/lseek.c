# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd, pid;
	char buff[100];
	fd = open("temp",O_RDWR | O_CREAT ,0666);
	write(fd,"Hello world aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",50);

	lseek(fd,0,SEEK_SET);
	read(fd,buff,5);
	buff[5] = '\0';
	printf(buff);
	printf("\n");
	
	lseek(fd,10,SEEK_CUR);
	read(fd,buff,5);
	buff[5] = '\0';
	printf(buff);
	printf("\n");

	lseek(fd,-50,SEEK_END);
	read(fd,buff,5);
	buff[5] = '\0';
	printf(buff);
	printf("\n");
				
}
