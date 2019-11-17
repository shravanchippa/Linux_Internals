/* This program illustrates the installing signal handler for SIGINT signal*/
#include<signal.h>

void sighandler(int signum)
{
	printf("Caught signal:%d pressed ctrl+c!!\n",signum);
	exit(1);
}
void sighandler1(int signum)
{
	printf("Caught signal:%d !!!!!!!!!!!!!\n",signum);
	exit(1);
}

main()
{
	int retval=0;
	signal(SIGINT,sighandler);
	retval=signal(SIGINT,sighandler1);
	printf("retval %d\n",retval);
	while(1)
	;	//printf("This is in infinite loop\n");
}
	
