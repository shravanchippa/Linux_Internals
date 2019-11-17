/* This program illustrtes how the priority of the process can be set for this program*/

#include<sched.h>
#include<sys/time.h>
#include<sys/resource.h>

main()
{	
	int i;
	printf("priority of this program  before setting a priority:%d\n",\
		getpriority(PRIO_PROCESS,getpid()));

	if(setpriority(PRIO_PROCESS,getpid(),6)==-1) {
			perror("setpriority");
			exit(1);
		}

	printf("priority of this program  after setting a priority:%d\n",\
		getpriority(PRIO_PROCESS,getpid()));

	nice(-20);
	
	printf("priority of this program  after setting a priority:%d\n",\
		getpriority(PRIO_PROCESS,getpid()));
	sleep(30);
}
