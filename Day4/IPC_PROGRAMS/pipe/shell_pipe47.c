/***************************************************************************
                          pipe.c  -  description
                             -------------------
    begin                : Wed Jul 23 2003
 ***************************************************************************/
// Sample code to illustrate the pipe

#include<stdio.h>

main()
{
	int pid,p[2];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		close(1);
		close(p[0]);
		dup(p[1]);
		execlp("ls","ls","-l",NULL);
	}
	else
	{
		wait(0);
		close(0);
		close(p[1]);
		dup(p[0]);
		execlp("wc","wc",NULL);
	}
}
		
		 
