#include <stdio.h>

int main ()
{
	printf ("After the exec my process ID is %d\n",getpid());
	printf ("My parent process ID is %d\n",getppid());
	
	printf ("exec ends\n");
}
