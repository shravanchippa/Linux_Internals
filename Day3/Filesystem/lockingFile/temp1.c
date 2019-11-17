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
	write(fd,"xxxxxxxxxxxxxxxxxxxxxxxx",25);
		puts("The child process over");

	}
	else	{
	write(fd,"XXXXXXXXXXXXXXXXXXXXXXXX",25);
	if(lockf(fd,F_ULOCK,0) == -1)
		perror("lockf failed");
	write(fd,"ZZZZZZZZZZZZZZZZZZZZZZZ",25);
		printf("Process %d locked the file\n",getpid());
	}
}
