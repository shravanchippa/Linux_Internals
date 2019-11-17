	#include <stdio.h>
	int main ()
	{
		char *temp[4];
		temp[0] = "/root/process/execvp/ex2";
		temp[1] = "hello";
		temp[2] = "world";
		temp[3] = (char *)0;
		printf ("I am the parent my pid is %d\n",getpid());
		execvp(temp[0],temp);
		printf ("This will not print\n");
	} 
