	#include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>
	#include <unistd.h>

	int main ()
	{
		int pfds[2];
		char buf[30];

		if (pipe(pfds) == -1)
		{
			perror("Pipe");
			exit(1);
		}

	printf ("Writing to file descriptor %d\n",pfds[1]);
	write(pfds[1],"test",5);
	printf ("Reading from file descriptor %d\n",pfds[0]);
	read(pfds[0],buf,5);
	printf ("Reading.....%s\n",buf);
	}

