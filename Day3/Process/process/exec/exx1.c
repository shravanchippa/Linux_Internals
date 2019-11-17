/* ./exx1 /root/process/exx2 exx2 Hello world */
#include <stdio.h>

int main (int argc,char *argv[])
{
	printf ("Before exec my ID is %d\n",getpid());
	printf ("exec starts\n");
	execl(argv[1],argv[2],argv[3],argv[4],(char*)0);
	printf ("This will not print\n");
}
