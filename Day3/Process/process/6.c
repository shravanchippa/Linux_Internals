#include <stdio.h>

int main ()
{
	fork();
	printf ("The pid is %d\n",getpid());
}
