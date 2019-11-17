	#include <stdio.h>
	int main ()
	{
		int i = 0,j = 0,pid;
		pid = fork();
		
		if (pid == 0)
		{
			for(i=0;i<50000;i++)
			printf ("%d\t",i);
		}
		else
		if(pid > 0)
		{
			for(j=0;j<500;j++)
			printf("%d...",j);
		}
	}
			
