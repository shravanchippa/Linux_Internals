#include <stdio.h>

int main ()
{
	int pid;
	pid = fork();

	if (pid > 0)
		printf ("Parent process PID is %d\n",pid);
}
