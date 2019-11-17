/***************************************************************************
                          execlp.c  -  description
                             -------------------
    	begin                : Wed Jul 23 2003
	version no : 1.2
	system calls used : 

	pid_t fork(void);
       	int execlp(const char *file, const char *arg, ...);

	Description:
	Sample code to execute another process in the current process context
	using execlp()
***************************************************************************/
#include<unistd.h>
main()
{
	if(fork() == 0){
		execlp("ls","","-l","/etc",NULL); // path argument is not required
		printf("not printed\n");
	}
	else{
		wait(0);
	}
}
