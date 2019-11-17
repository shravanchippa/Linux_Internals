

# include <sys/types.h>
# include <pthread.h>
# include <signal.h>

void * th_fn1(void * p);
void * th_fn2(void * p);

void sigfn (int k);
void sigfn1 (int k);
void sigfn2 (int k);

int main()
{
        pthread_t t1,t2,t3,t4;
        int pid = getpid();

        system("clear");

    	signal(SIGUSR1, sigfn );
        pthread_create(&t2,NULL,th_fn2,"Thread Two");
	pthread_create(&t1,NULL,th_fn1,"Thread One");

	printf("main tid is :%u\n",pthread_self());

        pthread_kill(t1,SIGUSR1);
        pthread_kill(t2,SIGUSR1);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

        //sleep(100);
}


void * th_fn2(void * p)
{
    	char * str;
   	int i, pid;
    
    	str = (char *)p;
    	pid = getpid();
   
    	signal(SIGUSR1, sigfn2 );
	//kill(pid, SIGUSR1);
    
	printf("tid is :%u    \n",pthread_self());
     	printf ("%s: \t Started Now: \t For Process %d \n",str,pid);
	

	i=0;
    	while(i++ < 3)
    	{
       		printf("%s: \t Hello : \t %d \n",str,pid);
        	sleep(1);

    	}
    	printf("%s: \t Finished: \t For Process %d \n\n",str,pid);
}
void * th_fn1(void * p)
{
    	char * str;
   	int i, pid;
    
    	str = (char *)p;
    	pid = getpid();
   
    
    	signal(SIGUSR1, sigfn1 );
	printf("tid is :%u    \n",pthread_self());
     	printf ("%s: \t Started Now: \t For Process %d \n",str,pid);
	

	i=0;
    	while(i++ < 3)
    	{
       		printf("%s: \t Hello : \t %d \n",str,pid);
        	sleep(1);

    	}
    	printf("%s: \t Finished: \t For Process %d \n\n",str,pid);
}
void sigfn ( int k)
{
        printf("Yes I got the Signal: \t %u \n",pthread_self());
	printf("Signal number is %d\n",k);
}
void sigfn1 ( int k)
{
        printf("Yes I - in function got the Signal: \t %u \n",pthread_self());
	printf("Signal number is %d\n",k);
}
void sigfn2 ( int k)
{
        printf("Yes I got the Signal - level 2: \t %u \n",pthread_self());
	printf("Signal number is %d\n",k);
}
