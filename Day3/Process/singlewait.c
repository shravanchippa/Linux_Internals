/***********************************************************        ****
                                 wait.c  -  description
                                    -------------------
           begin                : Wed Jul 23 2003
*************************************************************        ****/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

main()
{
	int chpid1;
	if((chpid1 =fork())== 0) { //First child
		printf(" Child pid = %d\n",getpid());
			sleep(5);
		printf("First child exited\n");
		_exit(50);
	}
	else {
		int x;
		printf("Before wait())\n");
		wait(&x);//Recives childs exit status 
		printf("pid of parent is : %d\n",getpid());
		printf("pid of first child is : %d\n",chpid1);
		printf("\n exit status is %d\n",x/256);
	}
}
						
