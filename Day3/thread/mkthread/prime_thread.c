/***************************************************************************
	Description : Program to create and join newly created thread to main thread.
		sending parameter to thread and receving data from thread.

	Compile and link this program using 'lpthread' library 
	Thread lib functions used :

	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);

	pthread_join(pthread_t thread_id, void **thread_return);


	Source :ALP
***************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h> 

/* Compute successive prime numbers (very inefficiently). Return the
Nth prime number, where N is the value pointed to by *ARG. */

void* compute_prime (void* arg)
{
	int candidate = 2;
	int n = *((int*) arg);
	while (1) {
		int factor;
		int is_prime = 1;
		/* Test primality by successive division. */
		for (factor = 2; factor < candidate; ++factor)
			if (candidate % factor == 0) {
				is_prime = 0;
				break;
			}
	/* Is this the prime number we are looking for? */
		if (is_prime) {
			if (--n == 0)

		/* Return the desired prime number as the thread return value. */
				return (void*) candidate;
		}
		++candidate;
	}
	return NULL;
}

int main ()
{
	pthread_t thread;
	int which_prime = 5000;
	int prime;

	/* Start the computing thread, up to the 5,000th prime number. */
	pthread_create (&thread, NULL, compute_prime, &which_prime);

	/* Do some other work here... */

	/* Wait for the prime number thread to complete, and get the result. */
	pthread_join(thread, (void*) &prime);

	/* Print the largest prime it computed. */
	printf("The %dth prime number is %d.\n", which_prime, prime);
	return 0;
}
