//  Parent locked the file .
// When parent goes to sleep chiled will be scheduled
//But child is blocked scince it is trying to lock the file

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
		if(lockf(fd,F_LOCK,0) == -1)	//child is blocked here
			perror("lockf failed");
		printf("Process %d locked the file\n",getpid());
		puts("The child process over");

	}
	else	{
		puts("Parent is sleeping");
		sleep(5);
		printf("Process %d locked the file\n",getpid());
	}
}
