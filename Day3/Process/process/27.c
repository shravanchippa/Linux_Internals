	/*How to make parent to wait for more than one child*/

	#include <stdio.h>
	int main ()
	{
		int pid,dip;
		pid = fork();

		if(pid == 0)
		{
			printf ("1st child process id is %d\n",getpid());
			printf ("First process dead\n");
		}
		else
		{
			dip = fork();
			if(dip == 0)
			{
				printf ("2nd child process id is %d\n",getpid());
				printf ("Second process dead\n");
			}
			else
			{
				printf ("Child with pid %d died\n",wait(0));
				printf ("child wuth pid %d died\n",wait(0));
				printf ("Iam parent process and i am dying\n");
				sleep();
			}
		}
	}
