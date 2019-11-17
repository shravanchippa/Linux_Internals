# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd, pid1,pid2;
	char buff[100];
	fd = open("temp",O_RDWR | O_CREAT ,0666);
	write(fd,"world aaaaaaaaaaaaaaa",21);

	if((pid1 = fork()) == 0){
		lseek(fd,0,SEEK_SET);
		printf("Child\n");
		read(fd,buff,5);
		buff[5] = '\0';
		printf(buff);
	}
	else if ((pid2 = fork()) == 0){
		printf("Another child\n");
		read(fd,buff,5);
		buff[5] = '\0';
		printf(buff);
	}
	else
		waitpid(pid1,NULL,NULL);
		waitpid(pid2,NULL,NULL);
				
}
