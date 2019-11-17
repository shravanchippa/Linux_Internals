	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <unistd.h>


	int main ()
	{
		int pfds[2];
		char buf[30];

		pipe(pfds);

		if(!fork())
		{
				printf ("CHILD,writing to the pipe\n");
				write(pfds[1],"test",5);
				printf ("Child:exiting\n");
				exit(0);
		}
		else
		{
				printf ("PARENT:reading from pipe\n");
				read(pfds[0],buf,5);
				printf ("PARENT:reading......%s\n",buf);
				wait(NULL);
		}		
	}
