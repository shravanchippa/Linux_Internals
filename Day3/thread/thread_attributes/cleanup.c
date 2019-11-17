#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void cleanup(void *arg)
{
	printf("cleanup:  %s\n",(char *)arg);
}

void *th_fun1(void *arg)
{
	printf("Thread 1 to start\n");
	pthread_cleanup_push(cleanup,"thread 1 first handler");
	pthread_cleanup_push(cleanup,"thread 1 second handler");
	printf("thread 1 push over\n ");

	if(arg) return ((void *) 1);
	pthread_cleanup_pop(0);
	return ((void *)1);
}

void *th_fun2(void *arg)
{
	printf("Thread 2 to start\n");
	pthread_cleanup_push(cleanup,"thread 2 first handler");
	pthread_cleanup_push(cleanup,"thread 2 second handler");
	printf("thread 2 push over\n ");

	pthread_cleanup_pop(0);
	if(arg) 
		pthread_exit((void * )2);
}

main()
{
	pthread_t tid1, tid2;
	void * th_return;
	if(pthread_create(&tid1,NULL, th_fun1,(void *)1))
		perror("Thread create error\n");
	if(pthread_create(&tid1,NULL, th_fun2,(void *)1))
		perror("Thread create error\n");
	pthread_join(tid1, &th_return);
	printf("thread 1 exit code %d\n",(int )th_return);

	pthread_join(tid2, &th_return);
	printf("thread 2 exit code %d\n",(int )th_return);
}
