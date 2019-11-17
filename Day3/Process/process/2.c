#include <stdio.h>

int main ()
{
	int ppid;
	ppid = getppid();
	printf ("Parent Process ID is %d\n",ppid);
}
