	#include <stdio.h>
	
	int main ()
	{
		int ppid;
		ppid = getppid();
		printf ("Parent process id is %d\n",ppid);
	}
