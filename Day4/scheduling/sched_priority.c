/*********************************************************
                 sched_priority.c  -  description
                       -------------------
           begin                : Wed Jul 23 2003
           author               : (C) 2003 by Vikas
           email                : vikas@vsquareinfotech.com
***************************************************************/
#include<sys/time.h>
#include<sys/resource.h>

main()
{
	int prio,pid;
	pid = getpid();

	int ctr;
	prio = getpriority(PRIO_PROCESS,pid);
	printf(" The priority of the process%d is %d\n",pid,prio);

	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
		for(ctr = 0; ctr < 90000000; ctr++);
	setpriority(PRIO_PROCESS,pid,12);
	prio = getpriority(PRIO_PROCESS,pid);
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
	for(ctr = 0; ctr < 90000000; ctr++)
		for(ctr = 0; ctr < 90000000; ctr++);
	printf(" The modified priority of the process is %d\n",prio);
}
