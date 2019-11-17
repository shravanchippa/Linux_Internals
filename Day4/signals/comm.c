/* This is a simple program which illustrates the communication between processes using kill system call*/

# include <stdio.h>
#include<signal.h>
#include<sys/types.h>

void myhandler(int signum)
{
	printf("Sent SIGINT to parent\n");
}

main()
{
	int i;
	
	signal(SIGINT,myhandler);
	//signal(SIGKILL,myhandler);
	i=fork();	
	
	if(i==0) {
		printf("child pid is %d\n",getpid());
		printf("parent pid is %d\n",getppid());
		kill(getppid(),SIGINT);
	} else {
		wait(0);
	   	sleep(2);
	}

}	
