#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<time.h>
main()
{
	int prio,pid;
	pid=getpid();

	prio=getpriority(PRIO_PROCESS,0);
	printf("the priority of the process %d is %d\n",pid,prio);

	setpriority(PRIO_PROCESS,pid,5);
	prio=getpriority(PRIO_PROCESS,pid);
	printf("the priority of the process %d is %d\n",pid,prio);

	prio=nice(7);
	prio=getpriority(PRIO_PROCESS,pid);
	printf("the priority of the process %d is %d\n",pid,prio);

}
