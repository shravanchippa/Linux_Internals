# include <stdio.h>
# include <unistd.h>
# include <sys/select.h>
# include <sys/types.h>

main()
{
	fd_set	obj;
	char buff[10];
	int retval=0;
	struct timeval St;

	St.tv_sec = 1.0;
	St.tv_usec = 0;
	FD_ZERO(&obj);
	FD_SET(0,&obj);
	retval = select(1,&obj,0,0,&St);

	if(retval == -1)perror("Select");
	else	if(retval ){
		printf("Data is available now\n");
		read(0,buff,10);
	}	
	else	
		printf("Time is expired\n");
}
