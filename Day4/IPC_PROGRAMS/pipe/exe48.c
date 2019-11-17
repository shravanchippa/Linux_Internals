/***************************************************************************
 ***************************************************************************/
#include<stdio.h>

main()
{
	int pid,p[2];
	int sec[2];
	
	pipe(sec);
	pipe(p);
	
	pid = fork();
	if(pid == 0)
	{
		close(p[0]); //close read of pipe1
		dup2(p[1],1);  //dup stdout 
		execlp("ls","ls","-l",NULL);
	}
	else if(fork() == 0){
		printf("I am sec child\n");
		close(p[1]);
		close(sec[0]);
		dup2(p[0],0);
		dup2(sec[1],1);
		execlp("grep","grep","^d",NULL);
	}
	else{
		close(p[0]);
		close(p[1]);
		close(sec[1]);
		dup2(sec[0],0);

		execlp("wc","wc",NULL);

	}
}
