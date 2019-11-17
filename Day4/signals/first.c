# include <signal.h>
# include <stdio.h>
void sig_init(void);
main()
{
	printf("Press <^C> kye\n");
	signal(SIGINT,(void *)sig_init);
	for(;;);
}
void sig_init(void)
{
	printf("You have pressed the <^C> key\n");
	signal(SIGINT,SIG_DFL);
}
