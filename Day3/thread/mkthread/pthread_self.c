/***************************************************************************
	Description : Program to create and join newly created thread to main thread.

	Compile and link this program using 'lpthread' library 
	Thread lib functions used :
	
	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);
	pthread_join(pthread_t thread_id, void **thread_return);
	pthread_exit(void *return_value);

	pthread_t = pthread_self(void );

	pthread_equal(pthread_t thread1, pthread_t thread2);

***************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
# include <string.h>

void *thread_fun(void *arg);

char message[]="hello world";

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	system("clear");
	res=pthread_create(&a_thread,NULL,thread_fun,(void *)message);
	if(res !=0){
		perror("unable to create thread\n\n");
		exit(1);
	}
	printf("Newly created thread ID is %u\n\n",(unsigned int)a_thread);

	printf("Printing main thread ID %u\n\n",(unsigned int)pthread_self());
	printf("waiting for thread to finish\n");
	//Thread joining, catch exit value from the thread	
	res=pthread_join(a_thread,&thread_result);
	
	if(res !=0){
		perror("unable to join thread\n");
		exit(1);
	}
	
	printf("Message is %s now \n",message);
	

	if(pthread_equal(a_thread,*(pthread_t *)thread_result)!=0)
		printf("Threads are same\n");

	exit(0);
}

void *thread_fun(void *arg)
{
	pthread_t thread_id;
	printf("thread ID is %u\n",(unsigned int)pthread_self());
	thread_id = pthread_self();
	
	printf("I am new thread printing %s\n",(char * )arg);
	strcpy(arg,"bye");
	//exit with return value
	pthread_exit((void *)thread_id);
}
