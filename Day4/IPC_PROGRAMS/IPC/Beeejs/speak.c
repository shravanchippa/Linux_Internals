	#include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>
	#include <string.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>

	#define FIFO_NAME	"myfifo"

	int main ()
	{
		char s[300];
		int num,fd;

		/*don't forget to error check the stuff!!!*/
		mkfifo(FIFO_NAME,S_IFIFO|0666);

		printf ("Waiting for readers...\n");		
		fd = open(FIFO_NAME,O_WRONLY);
		printf ("Got the reader---type some stuff\n");
		
		while(gets(s),!feof(stdin))
		{
			if((num = write(fd,s,strlen(s))) == -1)
				perror("write");
			else
				printf ("Speak:Wrote %d bytes\n",num);
		}
	}
