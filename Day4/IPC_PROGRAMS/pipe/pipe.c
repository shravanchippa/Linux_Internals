/*************************************************************************
	program name: pipe1.c
	Description :This program describs how pipe is used to read and write 
			in singe process.
# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using pipe
		     
**************************************************************************/
# include<stdio.h>
#include<stdlib.h> 
#include<unistd.h> 
main()
{
	int 	pipefd[2],   n;
	char	buff[100];

	if(pipe(pipefd) < 0)
		perror("filed in openning pipe\n");
	printf("read fd = %d, write fd = %d\n",pipefd[0],pipefd[1]);
	
	if(fork() == 0){	//Creating the child

		close(pipefd[0]);	//Child closes read discriptor 

		//Child writes to pipe descriptor
		if(write(pipefd[1],"hello world.....!",18)!= 18)
			perror("filed in writing pipe\n");
		close(pipefd[1]);	//Child closes   write discriptor 
	}
	else{
		puts("I am parent\n");
	
		close(pipefd[1]);	//Parent closes write discriptor 

		//Parent reads from read descriptor
		if((n = read(pipefd[0],buff,5) < 0))
			perror("filed in writing pipe\n");
		write(1 , buff, n);	//Write to stdout
		if((n = read(pipefd[0],buff,6) < 0))
			perror("filed in writing pipe\n");
	
		write(1 , buff, n);	//Write to stdout

		close(pipefd[0]);
		_exit(0);
	}
}
