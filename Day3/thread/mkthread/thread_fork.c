/***************************************************************************
    Description : Program to create a thread and execute.Newly created thread executes
	print_xs function, both the threads print x and o's in time sharing basices.
	Thus The output will be	x's and o's are printed asynchronously,
	till you stop the process
	Source : ALP
	
	pthread Library functions used:
        int  pthread_create(pthread_t  *  thread, pthread_attr_t * attr, void *\
       (*start_routine)(void *), void * arg);

	Compile and link this program using the following code:
	% cc -o thread-create thread_create.c -lpthread 
***************************************************************************/

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include <pthread.h>
#include <stdio.h>

/* Prints x's to stderr. The parameter is unused. Does not return. */

void* print_xs (void* unused)
{
	while (1)
		fputc ('x', stderr);// or stdout
	return NULL;
}
void* print_zs (void* unused)
{
	while (1)
		fputc ('z', stderr);// or stdout
	return NULL;
}

/* The main program. */

main ()
{
	pthread_t thread_id;

/* Create a new thread. The new thread will run the print_xs
function. */

	pthread_create (&thread_id, NULL, print_xs, NULL);
	if(fork()==0){
		printf("I am child\n ");
		pthread_create (&thread_id, NULL, print_zs, NULL);
		sleep(10);
			/* Print o's continuously to stderr. */
	}else{
		while (1)
			fputc ('o', stderr);

		return 0;
	}
}

