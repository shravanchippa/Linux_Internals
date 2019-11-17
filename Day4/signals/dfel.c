//Program to illustrate default action

# include <signal.h>
# include <stdio.h>

void sig_init(int);
main()
{
	printf("Press <^C> kye\n");
	signal(SIGINT, (void *) sig_init);

	//Do something here

	//signal(SIGINT, SIG_DFL);
	for(;;);
}
void sig_init(int i)
{
	printf("You have pressed the <^C> key %d\n",i);
}
