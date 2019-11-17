# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd,fd1, newfd;
	fd = open("temp",O_RDWR | O_CREAT ,0666);
	printf("The file discriptor is %d\n",fd);

	fd1 = open("temp1",O_RDWR | O_CREAT ,0666);
	newfd=fcntl(fd,F_DUPFD,NULL);
	printf("The file discriptor is %d\n",newfd);
				
}
