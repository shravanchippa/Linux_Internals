/***************************************************************************
	Description : Program to illustrate joining threads. If main thread does not 
	wait for newly created threads to terminate, the termination of main thread 
	will make them to terminate abruptly. Thus we should make main thread to wait 
	for other threads to complete their work.

	Functions used :
        int  pthread_create(pthread_t  *  thread, pthread_attr_t * attr, void *\
	       (*start_routine)(void *), void * arg);

	int pthread_join(pthread_t th, void **thread_return);

	Source : ALP
***************************************************************************/
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
#include<stdlib.h> 

struct char_print_parms{
	char	character;
	int count;
};
const char arr[10];
/* Prints a number of characters to stderr, as given by PARAMETERS,
which is a pointer to a struct char_print_parms. */

void *char_print(void *parameters)
{
	/* Cast the cookie pointer to the right type. */
	struct char_print_parms *p = (struct char_print_parms *) parameters;
	int i;
	for (i = 0; i < p->count; ++i)
		write(1,&(p->character),1);
	pthread_exit("zzz");
}

main ()
{
	extern current;
	pthread_t thread1_id;
	pthread_t thread2_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;

	/* Create a new thread to print 30,000 x's. */
	thread1_args.character = 'x';
	thread1_args.count = 300000;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	/* Create a new thread to print 20,000 o's. */

	thread2_args.character = 'o';
	thread2_args.count = 200000;

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);

	/* Make sure the first thread has finished. */
	pthread_join (thread1_id, 0);

	/* Make sure the second thread has finished. */
	pthread_join (thread2_id, 0);


	return 0;
}
