

/* Child checks for locktest since parent locked the file child continues 
and lockes the file for next 20 to 70 chars */

# include <fcntl.h>
# include <unistd.h>
main()
{
	int fd, retvelue;
	pid_t pid;
	char   buff[100];

	if((fd = open("locktest",O_RDWR|O_CREAT, 0666)) == -1)
		perror("open file locktest\n");

	if(lockf(fd,F_LOCK,10) == -1)
		perror("lockf failed");

	if((pid = fork()) == 0){
		if(lockf(fd,F_TLOCK,10) == -1)
			perror("Already locked");
		else
			printf("%d process locked the file 1-10 chars\n",getppid());
		lseek(fd,20,0);
		
		if(lockf(fd,F_TLOCK,50) == -1)
			perror("Already locked");
		else
			printf("%d process locked the file 20-70 chars\n",getpid());
		puts("The child process over");
	}
	else	{
		puts("Parent is sleeping");
		sleep(5);
		printf("Process %d is over\n",getpid());
	}
}
