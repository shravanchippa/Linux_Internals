#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int data;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;
	
	memset(buffer,'\0',sizeof(buffer));
	
	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();
		if(fork_result == -1)
		{
			fprintf (stderr,"Fork Failure");
			exit(EXIT_FAILURE);
		}
		
		if(fork_result == 0)
		{
			data = read(file_pipes[0],buffer,BUFSIZ);
			printf ("Read %d bytes : %s\n",data,buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			data = write(file_pipes[1],some_data,strlen(some_data));
			printf ("Wrote %d bytes\n",data);
			wait(NULL);
		}
	}
	exit(EXIT_SUCCESS);
}










