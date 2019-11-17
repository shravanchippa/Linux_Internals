/***************************************************************************
                          execv.c  -  description
                             -------------------
    	begin                : Wed Jul 23 2003
	version no : 1.2
	system calls used : 

	pid_t fork(void);
        int execv(const char *path, char *const argv[]);

	Description:
	Sample code to illustrate execv()
***************************************************************************/
#include<stdio.h>
main()
{
	int pid;
	char *v[3];
	v[0] = "ls";
	v[1] = "-l";
	v[2] = NULL;

	execv("/bin/ls",v);

	printf(" This will not be printed\n");
}	
