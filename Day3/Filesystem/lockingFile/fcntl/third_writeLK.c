# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd, ctr ,retval;
	char buff[15];
	struct flock lockc, lockp1,lockp2;

	fd = open("testfile",O_CREAT|O_RDWR,0666);
	lockp1.l_type = F_WRLCK;
	lockp1.l_whence = 0;
	lockp1.l_start = 0;
	lockp1.l_len = 0;

	if((retval = fcntl(fd, F_SETLKW,&lockp1)) == -1)
		perror("parent write lock\n");
	printf("Parent %d\n",retval);

	if(fork() == 0){
		lockc.l_type = F_WRLCK;
		lockc.l_whence = 0;
		lockc.l_start = 0;
		lockc.l_len = 0;

		if((retval = fcntl(fd, F_SETLKW,&lockc)) == -1)
			perror("child write lock\n");
		else{
			printf("Child %d\n",retval);
			printf("Child Process over\n");
			for(ctr =0; ctr < 5 ;ctr ++){
				write(fd,"I am child....",15);
				sleep(1);
			} //end of loop
			lockc.l_type = F_UNLCK;
			if((retval = fcntl(fd, F_SETLK,&lockc)) == -1)
				perror("child write lock\n");
		}
	}//end of child
	else{
		for(ctr =0; ctr < 5 ;ctr ++){
			write(fd,"I am parent...",15);
			sleep(1);
		} //end of loop
	lockp1.l_type = F_UNLCK;
	if((retval = fcntl(fd, F_SETLK,&lockp1)) == -1)
		perror("parent write lock\n");

	printf("I am parent unlocked file...........\n");	
	wait(0);
	}
}//End of main

//en.wikipedia.org/viki/Microkernel

// Monoletic win 95 98 98se,winMe
//micro amiga, amoeba, minix, symbianos

// Hybrid winNT, win2000 ,2003 , xp, vista, netware, Draganfly BSD

