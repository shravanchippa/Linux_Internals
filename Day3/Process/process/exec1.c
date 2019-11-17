	#include <stdio.h>
	int main ()
	{
		int pid;
		pid = fork();
		if (pid == 0)
		{
			printf ("Exec starts\n");
			execl("/bin/ls","ls","-l",(char *)0);
			printf ("Execl did not work\n");
		}
		else
		{
			wait(0);
			printf ("Parent:Is completed in child\n");
		}
	}
