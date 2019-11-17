# include <sys/types.h>
# include <unistd.h>
main()
{
	pid_t pid;
	if((pid = fork()) >0){
		printf("I am parent my pid is %d\n",getpid());
		//wait(NULL);
		sleep(10);
		printf(" my chaild's pid is %d\n",pid);
	}
	else if (pid == 0){
		int i;
	//	for(i =0; i < 900000000UL; i++);
		printf("I am child my pid is %d\n",getpid());
	}
}
