	#include <stdio.h>
	int main ()
	{
		printf ("After the exec process id is %d\n",getpid());
		printf ("My parent process id is %d\n",getppid());
		
		printf ("exec ends\n");
	}
