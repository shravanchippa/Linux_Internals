# include <sys/types.h>
# include <unistd.h>
main()
{
	pid_t pid;
	if((pid = fork()) ==0){
		printf("I am chaild my pid is %d\n",getpid());
		printf("my parent's pid is %d\n",getppid());
		sleep(250);
		printf("\nI am chaild my pid is %d\n",getpid());
		printf("my parent's pid is %d\n",getppid());
	}
	else{
		exit(0);
		printf("I am parent my pid is %d\n",getpid());
		printf(" my chaild's pid is %d\n",pid);
	}
}
