/****************************************************************************
	Program name:   fifo_client.c
	Description: 	this is client function reads file name from stdin.
			Using write system call the file name is writen into
			fifo. Then waits to read from fifo as soon as other
			process	writes into fifo this process reads from fifo, 
			and puts to stdout.
	Source : R.Stevens
	Comments send to vikaskaranth@hotmail.com
******************************************************************************/
# include <stdio.h>

# define MAXBUF	1024

client(int  readfd,  int writefd)
{
	char	buff[MAXBUF];
	int	n;
	
	puts("Enter file name\n");
	scanf("%s",buff);	//reading file name
	n = strlen(buff);
	
	if(buff[n-1] == '\n')
		n--;
	if(write(writefd,buff, n) !=n) //writing file name into fifo
		perror("client: write error\n");
	while((n = read(readfd,buff,MAXBUF)) > 0)  // reading from fifo
		if(write(1,buff,n)!= n)		// printing in stdout
			perror("client: error\n");
	if(n < 0)
		perror("Client: write error\n");
}
