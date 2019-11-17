#include <stdio.h>

int main ()
{
	int pid;
	int i = 10;
	pid = fork();
		
	if (pid == 0)
	{
		printf ("The initial value of i in the child  is %d\n",i);
		i += 10;
		printf ("Value of i after increment in child is %d\n",i);
	}
	else
	{
		wait(0);
		printf ("Value on i in parent is %d\n",i);	
	}
}
