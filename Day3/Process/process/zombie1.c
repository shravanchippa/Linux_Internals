	#include <stdio.h>
	int main ()
	{
		if (fork() > 0)
		{
			printf ("Parent\n");
			sleep(50);
		}
	}
