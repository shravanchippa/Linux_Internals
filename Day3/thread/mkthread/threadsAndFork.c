//Program to show that child process doesn't inherit , threads.

# include<sys/types.h>
# include<pthread.h>
#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 

void * th_fn(void *);

int global = 29;

main()
{
    pthread_t t1,t2;

    pthread_create(&t1,NULL,th_fn,"Thread One");
    pthread_create(&t2,NULL,th_fn,"Thread Two");

    if (fork () == 0)
    {
        sleep(3);
    }
    else{
	    pthread_join(t1,NULL);
	    pthread_join(t2,NULL);
	    wait( (int * ) 0);
    }
}


void * th_fn(void * p)
{
    char * str;
    int i, pid;

    str = (char *)p;
    pid = getpid();

    printf("Global is %d\n",++global);
    printf ("%s: \t Started Now: \t For Process %d \n\n",str,pid);

    i=0;
    while(i++ < 3)
    {
    	printf("%s: \t Resource Use Here: \t %d \n\n", str, pid);
        sleep(1);
    }
   printf("%s: \t Finished: \t For Process %d \n\n",str,pid);
}
