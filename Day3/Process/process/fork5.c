	#include <stdio.h>
	int main ()
	{
		int pid;
		pid = fork();
			
		if (pid == 0)
			printf ("Child process\n");
	}
