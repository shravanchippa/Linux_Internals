# include <stdio.h>

# define MAXBUF	1024

client(int  readfd,  int writefd)
{
	char	buff[MAXBUF];
	int	n;
	puts("Enter file name\n");
	scanf("%s",buff);
	n = strlen(buff);
	if(buff[n-1] == '\n')
		n--;
	if(write(writefd,buff, n) !=n)
		perror("client: write error\n");
	while((n = read(readfd,buff,MAXBUF)) > 0){
		if(write(1,buff,n)!= n)
			perror("client: error\n");
	}
	if(n < 0)
		perror("Client: write error\n");
}
