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

void* print_xs (void* unused)
{
	int i=0;
	while (i< 900000000UL)
		printf("%d\t",i++);
	//sleep(1);
	printf("\n");
	return NULL;
}

/* The main program. */

main ()
{
	pthread_t thread_id;
	pthread_attr_t  attr;

	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	pthread_create (&thread_id, &attr, print_xs, NULL);

	pthread_attr_destroy(&attr);
	
	printf("main thread exiting.........\n");	
	//No need to join the second thread
	sleep(2);
}

