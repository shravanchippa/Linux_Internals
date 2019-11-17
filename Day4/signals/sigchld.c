# include <signal.h>
void sig_init(void);
main()
{
	unsigned int pid, i;
	if((pid = fork()) == 0)
		sleep(1);
	else {
		signal(SIGCHLD,sig_init);
		for(i=0;i < 1000000000;i++) ;
		printf("parent exiting\n");
	}
}
void sig_init(void)
{
	printf("child terminated\n");
}
