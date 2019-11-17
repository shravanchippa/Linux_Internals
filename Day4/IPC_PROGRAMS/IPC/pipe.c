#include <stdio.h>
#include <unistd.h>

main ()
{
	int pid;
	int c[2];
	pipe(c);

	printf ("%d %d\n",c[0],c[1]);
	
	pid = fork();

	if (fork == 0)
	{
		close(0);
		dup(c[1]);
		close(c[0]);
		execlp("ls","ls","-al",NULL);
	}
	else
	{
		close(c[1]);
		dup(c[0]);
		close(1);
		execlp("less","path",NULL);
	}
}
