/*This program illustrates how a shared memory segment can be destroyed using shmctl system call*/
#include<sys/ipc.h>
#include<sys/shm.h>

main()
{
	int shmid;
	
	if((shmid=shmget(110,0,0))==-1) {
		perror("shmid");
		exit(1);
	}
	
	if(shmctl(shmid,IPC_RMID,0)==-1) {
		perror("shmctl");
		exit(1);
	}

	
	printf("Shared memory successfully removed\n");
}
