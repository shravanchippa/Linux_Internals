/***********************************************************        ****
                                 wait.c  -  description
                                    -------------------
           begin                : Wed Jul 23 2003
*************************************************************        ****/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

main()
{
	int chpid1,chpid2;
	int status;
	if((chpid1 =fork())== 0) { //First child
		printf(" Child pid = %d\n",getpid());
		sleep(5);
		printf("First child exited\n");
		_exit(100);
	}
	else {
		printf("Before wait())\n");
		wait(&status);//Recives first childs exit status 
		printf("XXXXXXXXXXXis : %d\n",status/256);
		printf("pid of parent is : %d\n",getpid());
		printf("pid of first child is : %d\n",chpid1);
	}
}
						
