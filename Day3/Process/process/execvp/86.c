	#include <stdio.h>
	#include <time.h>
	
	int main (int argc,char *argv[])
	{
		int pid;
		long a,b;
		time(&a);
		if ((pid=fork())==0)
		{
			execvp(argv[1],&argv[1]);
			perror("program failed");
		}
		else
		{
			wait((char*)0);
			time (&b);
			printf ("Time taken :%ld seconds\n",(b-a));
		}
	}
