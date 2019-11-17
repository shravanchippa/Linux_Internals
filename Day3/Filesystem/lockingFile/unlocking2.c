# include <fcntl.h>
# include <unistd.h>
main()
{
	int fd, i;
	pid_t pid;

	if((fd = open("locktest",O_WRONLY|O_CREAT, 0666)) == -1)
		perror("open file locktest\n");

	if(lockf(fd,F_LOCK,0) == -1)
		perror("lockf failed");

	if((pid = fork()) == 0){
		puts("Child is waiting to lock the file");			

		if(lockf(fd,F_LOCK,0) == -1)
			perror("lockf failed");

		printf("Process %d locked the file\n",getpid());
		puts("The child process over");

	}
	else	{
		puts("Parent is sleeping");
		sleep(5);
		printf("Process %d unlocked the file\n",getpid());

		if(lockf(fd,F_ULOCK,0) == -1)
			perror("lockf in unlock has failed");

		sleep(1);
		printf("Process %d is over\n",getpid());
	}
}
