#include<signal.h>
static void sighandler(int);
int main(void)
{
	int i,parentpid,childpid,status;

	/*prepare the sighandler routine to catch SIGUSR1 and SIGUSR2 */
	if(signal(SIGUSR1,sighandler)==SIG_ERR)
		printf("Parent:Unable to create handler for SIGUSR1\n");

	parentpid=getpid();
	if((childpid=fork())==0)	{
		kill(parentpid,SIGUSR1);/* raise the SIGUSR1 signal*/

		printf("\nHi I am here .............!\n\n");
		if(signal(SIGUSR2,sighandler)==SIG_ERR)
			printf("Child:Unable to create handler for SIGUSR2\n");

		/*Child Process begins busy-wait for a signal*/
		pause();
		//sleep(4);
		printf("done %d\n",getpid());
	}
	else	{
		kill(childpid,SIGUSR2);/* raise the SIGUSR2 signal*/
		//printf("Parent:Terminating child.....\n");
		//	sleep(1);
		wait(&status);/*Parent waiting for the child termination*/
		//kill(parentpid,SIGTERM);/*Parent  raising the SIGTERM signal*/
		printf("done %d\n",getpid());
	}
}

static void sighandler(int signo)
{
	switch(signo)
	{
		case SIGUSR1:/* Incoming SIGUSR1 signal*/
			printf("Parent:Recieved SIGUSR1 \n");
			break;
		case SIGUSR2:/*Incoming SIGUSR2 signal*/
			printf("Recieved SIGUSR2\n");
			break;
		default:
			printf("This should not be printed\n");
	}
	return;
}

