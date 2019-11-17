# include <stdio.h>
# include<fcntl.h>

main()
{
	int fd, pid, retval;
	struct flock lockc, lockp1,lockp2;

	if((fd = open("testlock",O_RDWR)) == -1) perror("opening file");

	lockp1.l_type = F_WRLCK;
	lockp1.l_whence = 0;
	lockp1.l_start = 0;
	lockp1.l_len = 15;

	if((retval = fcntl(fd, F_SETLK,&lockp1)) == -1)
		perror("parent write lock\n");
	printf("Parent %d\n",retval);

	if((pid = fork()) == 0){
		puts("\n\nChild starts here");
		
	//	if((retval = fcntl(fd, F_GETLK,&lockc)) == -1)
	//		perror("child write lock  :");

	/*	printf("retval is %d\n",retval);
		printf("process %d has locked this section\n",lockc.l_pid);
		printf("lock type   %d\n",lockc.l_type);
		printf("whence 		%d\n",lockc.l_whence);
		printf("start 		%d\n",lockc.l_start);
		printf("lenth is 	%d\n",lockc.l_len);
	*/
		lockc.l_type = F_WRLCK;
		lockc.l_whence = 0;
		lockc.l_start = 60;
		lockc.l_len = 75;

		if((retval = fcntl(fd, F_SETLK,&lockc)) == -1)
			perror("child write lock\n");
		printf("Child %d\n",retval);
		printf("Child Process over\n");
	}
	else {
		wait(0);
		//if((retval = fcntl(fd, F_GETLK,&lockp2)) == -1)
		//	perror("Parent write lock\n");
		
		/*printf("retval is %d\n",retval);
		printf("process %d has locked this section\n",lockp2.l_pid);
		printf("lock type   %d\n",lockp2.l_type);
		printf("whence 		%d\n",lockp2.l_whence);
		printf("start 		%d\n",lockp2.l_start);
		printf("lenth is 	%d\n",lockp2.l_len);
		*/
		printf("Parent Process over\n");
	}
}
