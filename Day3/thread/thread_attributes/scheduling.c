/***************************************************************************
	Description : 

	Compile and link this program using the following code:
	% cc -o detach deached.c -lpthread 

	Thread lib functions used :
	
	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);

	pthread_attr_init(pthread_attr_t *attr);

	pthread_attr_setdetachstate(pthread_attr__t *attr, int datachstate);

	pthread_attr_destroy(pthread_attr_t  *attr);
		
	Source : ALP
***************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void* thread_function (void* arg);
char message[]="hello world";

int thread_finished = 0;

int max_priority;
int min_priority;
struct sched_param scheduling_value;

/* The main program. */

main ()
{
	int res;
	pthread_t thread_id;
	pthread_attr_t  attr;

	//initializing the thread attribute object
	if((res = pthread_attr_init(&attr)) != 0){
		perror("pthread_attr_init\n");
		exit(EXIT_FAILURE);
	}
	if(pthread_attr_setschedpolicy(&attr,SCHED_RR)!= 0){
		perror("setting scheduling policy failed\n");
		exit(EXIT_FAILURE);
	}
	
 	max_priority = sched_get_priority_max(SCHED_RR);
	min_priority = sched_get_priority_min(SCHED_RR);

	//scheduling_value.sched_priority = min_priority;
	scheduling_value.sched_priority = 20;
	if(pthread_attr_setschedparam(&attr, &scheduling_value)!=0 ){
		perror("setting scheduling policy error\n");
		exit(EXIT_FAILURE);	
	}

	if(pthread_create (&thread_id, &attr, thread_function, (void *)message)!= 0){
		perror("pthread_create\n");
		exit(EXIT_FAILURE);	
	}

	if(!thread_finished){
		sleep(2);
		printf("\nwaiting for thread to finish ...........\n");
	}
	pthread_attr_destroy(&attr);
	printf("Other thread finished\n");
	exit(EXIT_SUCCESS);
}

void* thread_function (void* arg)
{
	printf("thread function is running argument is %s\n",(char *)arg);
	printf("The maximum priority is %d\n",max_priority);
	printf("The minimum priortity is %d\n",min_priority);
	printf("Second thread setting finished flag and exitinging.......... \n");
	thread_finished = 1;
	pthread_exit(NULL);
}
