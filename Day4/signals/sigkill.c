#include<signal.h>

void sighandler(int signum)
{
	printf("Caught signal:%d pressed ctrl+c!!\n",signum);
	exit(1);
}

main()
{
	signal(SIGKILL,sighandler);
	while(1)
	printf("This is in infinite loop\n");
}
	
