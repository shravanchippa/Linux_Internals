/***************************************************************************
	Description : Program to send parameter to thread whiling creating thread.

	Library functions used:

	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);
	
	int pthread_mutex_init(pthread_mutex_t , pthread_mutex_attr_t);
	
	int pthread_mutex_lock(pthread_mutex_t *);//Locking using mutex
	
	int pthread_mutex_ulock(pthread_mutex_t *);//Locking using mutex

	int pthread_mutex_destroy(pthread_mutex_t *);
	version : 1.2
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
***************************************************************************/
#include <pthread.h>
#include <stdio.h>

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

void *char_print(void *parameters);

//Creating mutex object
pthread_mutex_t	mute;

/* The main program. */

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	pthread_mutex_init(&mute,NULL);//initializing mutex object
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
	
	pthread_mutex_destroy(&mute);

	return 0;
}

void *char_print(void *parameters)
{
	/* Cast the cookie pointer to the right type. */

	struct char_print_parms *p = (struct char_print_parms *) parameters;
	int i;

	pthread_mutex_lock(&mute);//Locking using mutex

	for (i = 0; i < p->count; ++i)//thread safe operation
		fputc (p->character, stderr);

	pthread_mutex_unlock(&mute);//unlocking using mutex
	return NULL;
}

