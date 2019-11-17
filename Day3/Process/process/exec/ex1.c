#include <stdio.h>
#include <fcntl.h>

int main ()
{
	printf ("Before exec my ID is %d\n",getpid());
	printf ("My parent process ID is %d\n",getppid());
	
	printf ("exec starts\n");
	execl ("/root/process/exec/ex2","ex2",(char*)0);
	printf ("this will not print\n");
}

