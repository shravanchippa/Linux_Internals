	#include <stdio.h>
		
	int main (int argc,char *argv[])
	{
		printf ("I am the child after execl my process id is %d\n",getpid());
		printf ("Child is %s and its arguments are %s %s\n",argv[0],argv[1],argv[2]);
		printf ("exec ends\n");
	}
