/***************************************************************************
	Description : Cancellation is mechanism a thread can cancel
	 the execution of other thread. Here main thread cancelling the newly
	created thread after 4 seconds.

	pthread_create(pthread_t *third_id,pthread_attr_t *attr,\
	 void *(*start_routine)(void  *),void  *arg);

	pthread_join(pthread_t thread_id, void **thread_return);

	pthread_exit(void *return_value);
	pthread_cancel(pthread_t * threadid);
	pthread_setcancelstate(int state, int *oldstate);
	pthread_setcanceltype(int type, int *oldtype);
***************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_fun(void *arg);


int main()
{
	int res;
	int ctr;
	pthread_t a_thread;
	void *thread_result;
	res=pthread_create(&a_thread,NULL,thread_fun,NULL);
	if(res!=0){
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}

	sleep(4);
	printf("cancelling thread\n");

	res=pthread_cancel(a_thread);
	if(res!=0){
		perror("Thread cancellation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("waiting for thread to finish..........\n");
	res=pthread_join(a_thread,&thread_result);
	if(res !=0){
		perror(" Thread join failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void *thread_fun(void *arg)
{
	int i,res;
	int old, oold;

	res=pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,&old);
	if(res!=0){
		perror("setting cancel state failed\n");
		exit(EXIT_FAILURE);
	}
	//res=pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&oold);
	res=pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,&oold);

	if(res!=0){
		perror("setting cancel type failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("thread fun is running\n");
	for(i=0;i<10;i++){
		printf("thread is still running (%d).....\n",i);
		sleep(1);
	}
}
