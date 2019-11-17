# include <stdio.h>
# include <fcntl.h>
main()
{
	int fd, ctr ,r,retval;
	char buff[15];
	struct flock  lockc,lockp;
	
	fd = open("test",O_CREAT|O_TRUNC|O_RDWR,0666);
	if(fork() == 0){
		lockc.l_type = F_WRLCK;
		lockc.l_whence = 0;
		lockc.l_start = 0;
		lockc.l_len = 0;
		//Child is locking the file
		if((retval = fcntl(fd, F_SETLK,&lockc)) == -1)
			perror("Child write lock\n");
		else{	
		printf("In child retval is %d\n",retval);
		for(ctr =0; ctr < 500 ;ctr ++){
			write(fd,"x",1);
			for(r =0; r < 50000 ;r ++);
			//sleep(1);
		}
		}
		printf("Child Process over\n");
	}//end of child
	else{
		lockp.l_type = F_WRLCK;
		lockp.l_whence = 0;
		lockp.l_start = 0;
		lockp.l_len = 0;
		//Child is locking the file
	//	if((retval = fcntl(fd, F_SETLKW,&lockp)) == -1)
	//		perror("lock");
		//else{	
		for(ctr =0; ctr < 500 ;ctr ++){
			write(fd,"y",1);
			for(r =0; r < 50000 ;r ++);
			//sleep(1);
		} //end of loop
//	}
	}
}

//en.wikipedia.org/viki/Microkernel

// Monoletic win 95 98 98se,winMe
//micro amiga, amoeba, minix, symbianos

// Hybrid winNT, win2000 ,2003 , xp, vista, netware, Draganfly BSD

