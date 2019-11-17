/***************************************************************************
                          execvp.c  -  description
                             -------------------
    	begin                : Wed Jul 23 2003
	version no : 1.2
	system calls used : 

	pid_t fork(void);
        int execvp(const char *file, char *const argv[]);

	Description:
	Sample code to illustrate execvp()
***************************************************************************/
#include<stdio.h>
main()
{
	int pid;
	char *v[3];
	v[0] = "ls";
	v[1] ="-l";
	v[2] = NULL;
	if(fork()== 0){
		execvp("ls",v);
		printf(" This will not be printed\n");
	}
	else
		wait(0);
}	
