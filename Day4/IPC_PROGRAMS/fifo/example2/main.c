/****************************************************************************
	Program name: server.c
	Description : Parent child communication using named pipe.
****************************************************************************/

# include "my_ipc.h"
# include <stdio.h>

# define	FIFO1	"/tmp/fifo1"	//fifos can be created in users home
# define	FIFO2	"/tmp/fifo2"	//directory also.

void	server(int, int);
void	client(int, int);


main()
{
	int	readfd, writefd ,pid;
				//fifo is created with user read and write
				//permission.
	if((mkfifo(FIFO1, S_IRUSR | S_IWUSR)) < 0){
		perror("Fifo1 failed\n");
		exit(1);
	}
	if((mkfifo(FIFO2, S_IRUSR | S_IWUSR)) < 0){
		perror("Fifo1 failed\n");
		exit(2);
	}
	
	if((pid = fork()) == 0){
		readfd = open(FIFO1, 0, 0);//child opens fifo1 for read
		writefd = open(FIFO2, 1, 0);//child opens fifo2 for write
		//child process calls server function 

		server(readfd, writefd);
		exit(3);
	}
	writefd = open(FIFO1, 1, 0);
	readfd = open(FIFO2, 0, 0);
					//Parent becomes client	process
	client(readfd, writefd);

	 //parent wait till exit status returned is equal to pid(current child)	
	waitpid(pid,NULL,0);  	
	close(readfd);
	close(writefd);

	unlink(FIFO1);	//removing fifo from /tmp
	unlink(FIFO2);
	exit(0);
}
