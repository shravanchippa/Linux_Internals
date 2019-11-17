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

		printf ("Waiting for writers...\n");		
		fd = open(FIFO_NAME,O_RDONLY);
		printf ("Got a writer:\n");
		
		do{
			if((num = read(fd,s,300)) == -1)
				perror("read");
			else
			{
				s[num] = '\0';
				printf ("Hear:read %d bytes:%s\n",num,s);
			}
		    }while(num > 0);
	}
			
		
