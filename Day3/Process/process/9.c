#include <stdio.h>

int main ()
{
	int pid;
	pid = fork();
	
	if (pid < 0)
		printf ("Fork Failed\n");
	else
		printf ("Fork Succeeded\n");
}
