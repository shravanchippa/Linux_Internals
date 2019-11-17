/* Now child trys to lock the file already locked by parent becoms dead lock.
Due to wait(0); parent waits child to terminate, child waits parent to unlock
oops.... dead lock */

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
		lseek(fd,10,0);
		if(lockf(fd,F_LOCK,10) == -1)	
			perror("lockf failed");
		lseek(fd,0,0);
		if(lockf(fd,F_LOCK,20) == -1)	
			perror("lockf failed");
		puts("The child process over");
	}
	else	{
		//puts("I am parent");
		sleep(3);
		lseek(fd,0,0);
		if(lockf(fd,F_ULOCK,20) == -1)	
			perror("lockf failed");
		printf("Process %d is over\n",getpid());
	}
}
