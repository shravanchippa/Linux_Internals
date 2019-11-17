#include <stdio.h>
/* ./ex1 /bin/ls ls -l */
int main (int argc,char *argv[])
{
	printf ("Before exec my ID is %d\n",getpid());
	printf ("File-Perm no.od links groupswondersizedateName\n");
	printf ("exec starts\n");
	execl (argv[1],argv[2],argv[3],argv[4],(char*)0);
	printf ("this will not print\n");
}
