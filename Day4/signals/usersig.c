# include <signal.h>
static void sig_usr1(int);
static void sig_usr2(int);
main()
{
	if(signal(SIGUSR1, sig_usr1) == SIG_ERR)
		perror("can't catch SIGUSR1");
	if(signal(SIGUSR2, sig_usr2) == SIG_ERR)
		perror("can't catch SIGUSR2");
	for(;;) ;//pause();
}

static void sig_usr1(int signo)
{
	if(signo == SIGUSR1)
		printf("recived SIGUSR1\n"); 
		system("date");
		printf("recived signal%d\n",signo);
}
static void sig_usr2(int signo)
{
	if(signo == SIGUSR2)
		printf("recived SIGUSR2\n"); 
		system("cal");
		printf("recived signal%d\n",signo);
}
