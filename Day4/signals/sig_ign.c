//Program to illustarte SIG_IGN 
// Here we are ignoring SIGINT

# include <signal.h>
main()
{
	printf("Press <^C> kye\n");
	signal(SIGINT, SIG_IGN);
	for(;;);
}
