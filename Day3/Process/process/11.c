#include <stdio.h>

int main ()
{
	int pid;
	pid = fork();
	
	if (pid == 0)
	{
		printf ("I am the child,my process ID is %d\n",getpid());
		printf ("The child's parent process ID is %d\n",getppid());
		sleep(20);
		printf ("I am the child,my process ID is %d\n",getpid());
		printf ("The child's parent process ID is %d\n",getppid());
	}
	else
	{
		printf ("I am the parent,my process ID is %d\n",getpid());
		printf ("The parent's parent process ID is %d\n",getppid());
	}
}
