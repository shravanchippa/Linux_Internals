#include <stdio.h>
/* Two zombies are created */
int main ()
{
	int pid,dip;
	pid = fork();
	
	if (pid == 0)
	{
		printf ("1st child process is %d\n",getpid());
		printf ("first-child terminating\n");
	}
	else
	{
		dip = fork();
		if (dip == 0)
		{
			printf ("2nd child process is %d\n",getpid());
			printf ("second-child terminating\n");
		}
		else 
		{
			printf ("Child with pid %d died\n",wait(0));
			printf ("Child with pid %d died\n",wait(0));
			printf ("I am parent\n");
			sleep();
		}
	}
}
