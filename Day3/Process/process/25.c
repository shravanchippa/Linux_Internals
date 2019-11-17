	/*How to make parent to wait for more than one child*/

	#include <stdio.h>
	int main ()
	{
		int pid,dip,cpid;
		pid = fork();

		if(pid == 0)
		{
			printf ("1st child process id is %d\n",getpid());
			printf ("First child process terminating from memory\n");
		}
		else
		{
			dip = fork();
			if(dip == 0)
			{
				printf ("2nd child process id is %d\n",getpid());
				printf ("Second process terminating\n");
			}
			else
			{
				cpid = wait(0);
				printf ("child with pid %d died\n",cpid);
				cpid = wait(0);
				printf ("Child with pid %d died\n",cpid);
				printf ("Iam parent process and i am dying\n");
			}
		}
	}
