	#include <stdio.h>
	int main ()
	{
		int pid;
		int i = 10;
		pid = fork();
		if (pid == 0)
		{
			printf ("The initial value i in the child process is %d\n",i);
			i+=10;
			printf ("Value of variable i in the child process after increment is %d\n",i);
			printf ("Child terminated\n");
		}
		else
		{
			wait(0);
			printf ("value of i in parent process is %d\n",i);
		}
	}
