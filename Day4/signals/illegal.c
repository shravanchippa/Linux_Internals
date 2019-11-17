# include <signal.h>
void sigkey(int);

main()
{
	int	i=0,j = 10;
	//signal(SIGFPE,SIG_DFL);
	signal(SIGFPE,sigkey);
	j = j / i;
}
void sigkey(int   sigky)
{
	printf("The process recived %d\n",sigky);
}
