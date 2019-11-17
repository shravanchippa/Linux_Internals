# include <sys/types.h>
# include <sys/sem.h>
# include <sys/ipc.h>
# include <stdio.h>
# include<pthread.h>
# include<unistd.h>
union semun{
	int val;
	struct semid_ds   *buf;
	unsigned short  array;

	struct seminfo    *__buff;
};

void * th_fun(void *);

union semun  u;
int    sid;
key_t  key;
int    pid,   sid;
struct sembuf su, sl;


main()
{
	pthread_t	t1, t2, t3, t4;

	unsigned short int  key;
	key = ftok("semaphore.c",100);
	sid = semget(key,1,IPC_CREAT | 0666);
	printf("semaphore created by %d\n",getpid());
	u.val = 2;
	semctl(sid,0,SETVAL,u);
	printf("Semaphore initialized to %d\n",u.val);

	pid = getpid();


	sl.sem_num = 0;
	sl.sem_op = -1;
	sl.sem_flg = SEM_UNDO ;
	su = sl;
	su.sem_op = 1;
	
	pthread_create(&t1, NULL, th_fun,"Thread One");
	pthread_create(&t2, NULL, th_fun,"Thread two");
	pthread_create(&t3, NULL, th_fun,"Thread three");
	pthread_create(&t4, NULL, th_fun,"Thread four");

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	//semctl(sid,0,IPC_RMID);
	printf("Semaphore removed\n");
}
void * th_fun(void *p)
{
	char   *str;
	int i = 0;

	str = (char * )p;
	printf("%s is Trying to lock semaphore  %d\n\n",str, pid);
	if(semop(sid,&sl,1) == 0)
		printf("%s   Succedd in LOck   %d\n\n",str,pid);

	while(++i < 3)	{
		printf("%s   Resourec use here %d\n\n",str,pid);
		sleep(6);
	}
	semop(sid,&su,1);
	printf("%s  Unlock and Bye   %d\n\n",str,pid);
}
