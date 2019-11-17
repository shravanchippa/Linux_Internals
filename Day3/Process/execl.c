/***************************************************************************
                          fstat.c  -  description
                             -------------------
	begin                : Wed Jul 23 2003
	version no : 1.2
	system calls used : 

	pid_t fork(void);
	int execl(const char *path, const char *arg, ...);

***************************************************************************/
# include <unistd.h>
main()
{
	if(fork() == 0){ //Child executes cal here
		printf("Hi, I am child speaking..........\n");

		execl("/usr/bin/cal","cal","3","1980",NULL);

		printf("Bye..... But I don't print this..... why?\n");
	}
	else{
		wait(0);
		printf("I am parent speaking........\n");
	}
}
