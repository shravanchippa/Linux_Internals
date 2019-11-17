/*******************************************************************************
 Both the process are locking the same file's same region for read lock
 This is possible when we lock file for reading

struct flock {
             ...
             short l_type;    Type of lock: F_RDLCK,
                                 F_WRLCK, F_UNLCK 
             short l_whence;   How to interpret l_start:
                                 SEEK_SET, SEEK_CUR, SEEK_END 
             off_t l_start;    Starting offset for lock 
             off_t l_len;      Number of bytes to lock 
             pid_t l_pid;      PID of process blocking our lock
                                 (F_GETLK only) 
             ...
         };
*********************************************************************************/

# include <stdio.h>
# include<fcntl.h>

main()
{
	int fd, pid, retval;
	struct flock lockc, lockp;

	fd = open("testlock",O_RDONLY);

	lockp.l_type = F_RDLCK;
	lockp.l_whence = 0;	//SEEK_SET
	lockp.l_start = 10;
	lockp.l_len = 15;
	if((retval = fcntl(fd, F_SETLK,&lockp)) == -1) // Parent is locking the file
		perror("parent read lock\n");
	printf("Parent retval is %d\n",retval);
	
	//Child starts here
	if((pid = fork()) == 0){
		lockc.l_type = F_RDLCK;
		lockc.l_whence = 0;
		lockc.l_start = 10;
		lockc.l_len = 15;
		//Child is locking the file
		if((retval = fcntl(fd, F_SETLK,&lockc)) == -1)
			perror("Child read lock\n");

		printf("Child retval is %d\n",retval);
		printf("Child Process over\n");
	}
	else {
		sleep(3);
		printf("Parent Process over\n");
	}
}
