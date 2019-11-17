	#include <stdio.h>
	int main ()
	{
		int pid,i = 1,j=0;
		for(j=0;j<5;j++)
		{
			pid = fork();
			if (pid < 0)
				printf ("Maximum concurrent process are %d\n",i);
			if (pid == 0)
				i++;
			else
			{
				wait(0);
				exit(0);
			}
		}
	}
