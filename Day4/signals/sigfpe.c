/*This is a simple program which illustrates the signal handling for SIGFPE signal*/
#include<signal.h>
#include<stdio.h>
 
void sighandler(int signum)
{
	printf("Caught signal %d floating point error\n",signum);
	exit(1);
}

main()
{
	int num;
	
	signal(SIGFPE,sighandler);
	
	printf("Enter some number\n");
	scanf("%d",&num);
	num=num/0;
}
