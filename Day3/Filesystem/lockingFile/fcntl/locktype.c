# include <stdio.h>
# include<fcntl.h>

main()
{
	int fd, pid, retval;
	struct flock lockc, lockp,lockp1;

	fd = open("testlock",O_RDWR);

	lockp.l_type = F_WRLCK;
	lockp.l_whence = 0;
	lockp.l_start = 0;
	lockp.l_len = 55;

	if(fcntl(fd, F_SETLK,&lockp) == -1)
		perror("parent write lock\n");

/*	if((retval = fcntl(fd, F_GETLK,&lockp1)) == -1)
		perror("child write lock\n");

	printf("retval is %d\n",retval);
	printf("process %d has locked this section\n",lockp1.l_pid);
	printf("lock type   %d\n",lockp1.l_type);
	printf("whence 		%d\n",lockp1.l_whence);
	printf("start 		%d\n",lockp1.l_start);
	printf("lenth is 	%d\n",lockp1.l_len);

	printf("Parent ID is %d",getpid());

*/	if((pid = fork()) == 0){
		puts("\n\n\nChild starts here");
		printf("child	 ID is %d",getpid());

		if((retval = fcntl(fd, F_GETLK,&lockc)) == -1)
			perror("child write lock\n");

		printf("retval is %d\n",retval);
		printf("process %d has locked this section\n",lockc.l_pid);
		printf("lock type   %d\n",lockc.l_type);
		printf("whence 		%d\n",lockc.l_whence);
		printf("start 		%d\n",lockc.l_start);
		printf("lenth is 	%d\n",lockc.l_len);

		printf("Child Process over\n");
	}
	else {
		wait(0);
		//sleep(3);
		printf("Parent Process over\n");
	}
}
