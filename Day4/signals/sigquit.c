# include <signal.h>
# include <stdio.h>
static void sigfun(void);
main()
{
	printf("Press <^\\> kye\n");
	//signal(SIGQUIT,sigfun);
	signal(SIGQUIT,SIG_IGN);
	for(;;);
}
static void sigfun(void)
{
	printf("Recived signal\n");
}
