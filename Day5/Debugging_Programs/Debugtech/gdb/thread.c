#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_fun(void *arg);
void *thread_fun2(void *arg);
int run_now=1;
char message[]="hello world";

int main()
{
	int res;
	pthread_t a_thread,b_thread;
	void *thread_result;
	int print_count1=0;
	res=pthread_create(&a_thread,NULL,thread_fun,(void *)message);
	res=pthread_create(&b_thread,NULL,thread_fun2,(void *)message);

	printf("waiting for thread to finish\n");
	while(print_count1++ < 20) 
	{
	if (run_now ==1) 
	{
	printf("1");
	run_now=2;
	}
	else 
	sleep(1);
		
	}
	res=pthread_join(a_thread,&thread_result);
	printf("thread joined , it returned %s\n",(char *)thread_result);
	res=pthread_join(b_thread,&thread_result);
	printf("thread joined , it returned %s\n",(char *)thread_result);
	printf("Message is now %s\n",message);
	exit(0);
}

void *thread_fun(void *arg)
{
	int print_count2=0;
	printf("thread fun ,arg is %s\n",(char *)arg);
	while(print_count2++ < 20) 
	{
	if (run_now ==2)
	 {
	printf("2");
	run_now=1;
	 }
	else 
	sleep(1);
	}
		sleep(3);
		strcpy(message,"bye");
		pthread_exit("thank you");
}
void *thread_fun2(void *arg)
{
	int print_count2=0;
	printf("thread fun ,arg is %s\n",(char *)arg);
		sleep(30);
		strcpy(message,"bye");
		pthread_exit("thank you");
}
