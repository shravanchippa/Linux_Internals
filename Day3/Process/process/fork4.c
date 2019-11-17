	#include <stdio.h>
	int main ()
	{
		int pid;
		pid = fork();
		
		if (pid > 0)
			printf ("Parent pid is %d\n",pid);
	}
