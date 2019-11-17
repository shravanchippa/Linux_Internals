	#include <stdio.h>
	int main ()
	{
		int pid;
		pid = fork();

		if (pid == 0)
		{
			printf ("I am the child process,my process id is %d\n",getpid());
			printf ("The child's parent process id is %d\n",getppid());
		}
		else
		{
			printf ("I am the parent process,my process id is %d\n",getpid());
			printf ("The parents parent process id is %d\n",getppid());
		}
	}
