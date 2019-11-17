/***************************************************************************
	program name 	: pipe.c
	author  name	: R.stevens
	description	: This is a program to show how pipe can be used to 
			have two way communication. Here, Parent process calls
			client function, in other way child calls server. 
			Client reads file name from stdin, sends to server 
			via pipe. Server opens the file and sends content of 
			file to client through pipe2.
	Compilation : gcc -o pipe pipe.c pipe_client.c pipe_server.c
**************************************************************************/

# include <stdio.h>


void server(int, int);

void client(int, int);

main()
{
	int 	pipefd1[2], pipefd2[2], childfd, n;
	char	buff[100];

	if(pipe(pipefd1) < 0 || pipe(pipefd2) < 0)
		perror("filed in openning pipes\n");

	if((childfd = fork()) < 0){
		perror("can't fork");
		close(pipefd1);
		close(pipefd2);
	}
	
	else if(childfd > 0){		//Parent process
		close(pipefd1[0]);	//read1
		close(pipefd2[1]);	//write2
		
		client(pipefd2[0],pipefd1[1]);

		while(wait(( int *) 0)!= childfd)
				;
			close(pipefd1[1]);
			close(pipefd2[0]);
	} else {			// child process
		close(pipefd1[1]);	// write1
		close(pipefd2[0]);	// read2
		
		server(pipefd1[0],pipefd2[1]);
		
		close(pipefd1[0]);
		close(pipefd2[1]);
	}	
	exit(0);
}


