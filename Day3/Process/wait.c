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
	int chpid1,chpid2;
	if((chpid1 =fork())== 0) { //First child
		printf(" Child pid = %d\n",getpid());
		sleep(50);
		printf("First child exited\n");
	}
	else {
		printf(" pid of parent = %d\n",getpid());
		if((chpid2 = fork())== 0){  // Second child
			printf("pid of second child is %d\n",getpid());
			sleep(2);
			printf("second child exited\n");
		}
		else {
			printf("Before wait())\n");
			wait(NULL);//Recives first childs exit status 
			printf("pid of parent is : %d\n",getpid());
			printf("pid of first child is : %d\n",chpid1);
			printf("pid of second child is : %d\n",chpid2);
		}
	}
}
						
