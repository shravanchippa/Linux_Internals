	#include <stdio.h>
	int main ()
	{
		int i=0,pid;
		printf ("Ready to fokr\n");
		pid = fork();

		if (pid == 0)
		{
			printf ("Child starts\n");
			for(i=0;i<1000;i++)
				printf ("%d\t",i);
			printf ("Child ends\n");
		}
		else
		{
			wait(0);
			printf ("Parent starts\n");
			for(i=0;i<1000;i++)
				printf ("%d\t",i);
			printf ("Parent process ends\n");
		}
	}