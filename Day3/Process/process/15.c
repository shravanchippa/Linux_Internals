#include <stdio.h>

int main ()
{
	int i=0,pid;
	printf ("Ready to fork\n");
	pid = fork();

	if (pid == 0)
	{
		printf ("Child starts\n");							for(i=0;i<1000;i++)
			printf ("%d\t",i);
		printf ("Child ends\n");
	}
	else
	{
		wait(0);
		for (i=0;i<1000;i++)
			printf ("%d\t",i);
		printf ("Parent process end\n");	
	}
}
