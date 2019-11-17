/***************************************************************************
	Description : Program to send parameter to thread whiling creating thread.

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

	if(pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED)!= 0){
		perror("pthread_attr_setdetachstate\n");
		exit(EXIT_FAILURE);
	}

	if(pthread_create (&thread_id, &attr, thread_function, (void *)message)!= 0){
		perror("pthread_create\n");
		exit(EXIT_FAILURE);
	}

	if(!thread_finished){
		printf("waiting for thread to finish ...........\n");
		sleep(2);
	}
	pthread_attr_destroy(&attr);
	printf("Other thread finished\n");
	exit(EXIT_SUCCESS);
}

void* thread_function (void* arg)
{
	printf("thread function is running argument is %s\n",(char *)arg);
	printf("Second thread setting finished flag and exiting.......... \n");
	thread_finished = 1;
	//pthread_exit(NULL);
}
