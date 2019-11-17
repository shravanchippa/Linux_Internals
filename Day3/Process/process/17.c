#include <stdio.h>

int main ()
{
	int pid,dip,cpid;
	pid = fork();
	if (pid == 0)
	{
		printf ("1st child process ID is %d\n",getpid());
		printf ("first-child terminating from memory\n");
	}
	else
	{
		dip=fork();
		if (dip == 0)
		{
			printf ("2nd child process ID is %d\n",getpid());
			printf ("second-child terminating\n");
		}
		else
		{
			cpid = wait(0);
			printf ("child with pid %d died\n",cpid);
			cpid = wait(0);
			printf ("child with pid %d died\n",cpid);
			printf ("I am parent\n");
		}
	}
}
