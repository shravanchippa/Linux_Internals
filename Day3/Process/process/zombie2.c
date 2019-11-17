	#include <stdio.h>
	#include <sys/types.h>
	#include <unistd.h>

	int main ()
	{
		int pid;

		pid = fork();
		
		if (pid > 0)
		{
			//wait();
			sleep(50);
		}
		else
		{
			exit(0);
		}
		return 0;
	}
	


		
