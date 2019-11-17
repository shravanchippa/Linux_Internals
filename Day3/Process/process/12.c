#include <stdio.h>

/* creation of zombie process */
int main ()
{
	if (fork() > 0)
	{
		printf ("Parent\n");
		sleep(50);
	}
}
