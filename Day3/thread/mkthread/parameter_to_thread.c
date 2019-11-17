/***************************************************************************
	Description : Program to send parameter to thread whiling creating thread.
	This program has serious bug....!(intensionally done)
	It may happen that before two newly created threads completing their job 
	main thread may abort thus two threads remain accessing parameter structure which
	is already deallocated. Results unpredictable result.

	Compile and link this program using 'lpthread' library 
	Thread lib functions used :
	
	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);

	Source : ALP
***************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h> 

/* Parameters to print_function. */
struct char_print_parms
{
				/* The character to print. */
	char character;
			/* The number of times to print it. */
	int count;
};

/* Prints a number of characters to stderr, as given by PARAMETERS,
which is a pointer to a struct char_print_parms. */

void *char_print(void *parameters)
{
	/* Cast the cookie pointer to the right type. */

	struct char_print_parms *p = (struct char_print_parms *) parameters;
	int i;
	for (i = 0; i < p->count; ++i)
		fputc (p->character, stderr);
	return NULL;
}

/* The main program. */

main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;

		/* Create a new thread to print 30,000 'x's. */
	
	thread1_args.character = 'x';
	thread1_args.count = 300000;

	thread2_args.character = 'o';
	thread2_args.count = 300000;
	if(pthread_create(&thread1_id, NULL, char_print, &thread1_args)!=0 )
		perror("creating thread\n");
	
		/* Create a new thread to print 20,000 'o's. */
	pthread_create(&thread2_id, NULL, char_print, &thread2_args);
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);
	printf("\n\n\nI am terminating\n\n\n");
	return 0;
}

