	#include <stdio.h>
	int main ()
	{
		printf ("Before exec my id is %d\n",getpid());
		printf ("My parent process id is %d\n",getppid());
		
		printf ("Exec starts\n");
		execl("/root/process/ex2","ex2",(char*)0);
		printf ("this willnot print\n");
	}
