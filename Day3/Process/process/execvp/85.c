	#include <time.h>
	#include <stdio.h>
	
	int main (int argc,char *argv[])
	{
		int pid;
		if ((pid = fork()) == 0)
		{
			execvp(argv[1],&argv[1]);
			perror("Program failed");
		}
		else
		{
			wait(0);
		}
	}
