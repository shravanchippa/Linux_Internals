/***************************************************************************
                          execle.c  -  description
                             -------------------
    	begin                : Wed Jul 23 2003
	version no : 1.2
	system calls used : 

	pid_t fork(void);
       	int  execle(const  char  *path,  const  char  *arg  , ..., char * const envp[]);
	Description:
	Sample code to execute another process in the current process context
***************************************************************************/
#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h> 
char *env[]={"PATH=/bin"};
main()
{
	int pid;

	if(fork() == 0){
		execle("/bin/ls","ls","-l",NULL,env);
		printf(" This will not be printed\n");
	}
	else
		wait(0);
}	
