# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd, pid;
	int rt_value, pos;
	char buff[100];
	fd = open("temp",O_RDWR | O_CREAT ,0666);
	write(fd,"Hello world ",15);

	pos=lseek(fd,0,SEEK_CUR);
	printf("The position is %d\n",pos);
	
	fcntl(fd,F_SETFL,O_APPEND);
	write(fd,"Hello world",15);
	pos=lseek(fd,0,SEEK_CUR);
	printf("The position is %d\n",pos);
	close(fd);
}
