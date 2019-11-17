# include <fcntl.h>
void send_data(int wfd)
{
	int rfd,n,k;
	char buff[1024], name[20];

	/*  printf("Server: Give File name to write to socket \n");
	    scanf("%s",name);
	    n = strlen(name);
	    name[n] = '\0';
	*/ // Uncomment this to read a given file

	rfd = open("testfile.txt",O_RDONLY);
	if(rfd == -1)
		printf("Server: Could not open the file \n");
	else
		printf("Entered send data & opened the file \n");
	do{
	        n = read(rfd,buff,100);
	        write(wfd,buff,n);
	/*      printf("\n-----SERVER: %d -----\n",getpid());
        	write(1,buff,n);
	        printf("\n-----SERVER: %d -----\n",getpid());*/
		// Uncomment this to know what server is writing
		sleep(5);
	}while(n > 0);
	printf("Server: Write completed by send_data \n");
}

void recv_data(int rfd)
{
	int n;
	char buff[1024];

	printf("Client: entered recv_data function \n");
	do
	{
		n = read(rfd,buff,100);
		printf("\n-----CLIENT: %u -----\n",pthread_self());
		write(1,buff,n);
		printf("\n-----CLIENT: %u -----\n",pthread_self());
		sleep(5);
	}while(n > 0);
	printf("Client: read completed by recv_data \n");
} 
