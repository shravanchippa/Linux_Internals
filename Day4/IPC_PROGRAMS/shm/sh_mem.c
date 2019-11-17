/****************************************************************************
	Description: Program to test shared memory using mmap in this program
		     parent and child shares ptr. It is to show how shared
		     memory is shared between parent and child.
		     comment semaphore functions and run with 1000 times loops
	Compailation: This is application program. Compile this program along
		     with semaphore library program.
	Comments send to: vikaskaranth@rediffmail.com
****************************************************************************/		     
# include <stdio.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <fcntl.h>

main(int argc, char **argv)
{
	int 	fd, i, nloop, zero = 0;
	int	*ptr;
	int	semid;

	if(argc!= 3)
		printf("Usage :a.out <pathname> <#loops>\n");
	nloop = atoi(argv[2]);
	fd = open(argv[1], O_CREAT|O_RDWR,0600);
	write(fd, &zero, sizeof(int));
	ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);
	semid=sem_create(1234, 1);
	setbuf(stdout, NULL);	
	if(fork()==0){
		for(i = 0;i < nloop; i++){
			sem_wait(semid);
			printf("child:    %d",(*ptr)++);
			sem_signal(semid);
		}
		exit(0);
	}
	//sleep(1);
	for(i = 0;i < nloop; i++){
		sem_wait(semid);
		printf("parent:    %d",(*ptr)++);
		sem_signal(semid);
	}
	exit(0);
}	

/* Try the same program using shmat and shmdt system calls*/
