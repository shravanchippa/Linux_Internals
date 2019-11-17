/***************************************************************************
	Description :	Program to illustrate, if a thread generates a 
	termiination (SIGALRM) all the threads in the group will be terminated.
	
	system calls used : unsigned int alarm(unsigned int seconds);

***************************************************************************/

#include <pthread.h>
#include <stdio.h>

/* Prints x's to stderr. The parameter is unused. Does not return. */

void* print_xs (void* unused)
{
	alarm(2);
	while (1)
		fputc ('x', stderr);// or stdout
	return NULL;
}

/* The main program. */

main ()
{
	pthread_t thread_id;

/* Create a new thread. The new thread will run the print_xs
function. */

	pthread_create (&thread_id, NULL, print_xs, NULL);
			/* Print o's continuously to stderr. */
	while (1)
		fputc ('o', stderr);
	return 0;
}

