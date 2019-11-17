# include <stdio.h>
# include <signal.h>
# include <unistd.h>

void	sig_fun(int);

main()
{
	struct sigaction  signalact;

	signalact.sa_handler = sig_fun;
	sigemptyset(&signalact.sa_mask);
	signalact.sa_flags =0;
	sigaction(SIGINT, &signalact, 0);	
	while(1){
		printf("hello world\n");
		sleep(1);
	}
}

void	sig_fun(int signal)
{	
	printf("Hi, I got signal: %d\n",signal);
}
