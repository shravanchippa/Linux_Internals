/****************************************************************************
	Program name: fifo_server.c
	Description: This function is called in child process. 
		     It opens a file and reads contents of that file, 
		     then puts into fifo.
*****************************************************************************/

# include <stdio.h>

# define	MAXBUF	1024

server(int readfd,int  writefd)
{
	char	buff[MAXBUF];
	int	n, fd;

	if((n = read(readfd, buff, MAXBUF)) <= 0)
		perror("server: read error\n");
	buff[n] = '\0';
	if((fd = open(buff,0)) < 0)
		perror("server:open error\n");
	while((n = read(fd,buff,MAXBUF)) > 0)
		if(write(writefd,buff,n)!= n)
			perror("server: write error\n");
	if(n < 0)
		perror("server : read error\n");
}
