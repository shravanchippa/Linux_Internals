/*****************************************************************************
 	MODULE: 	fifoserver.c
	Description:	This is server program it reads from fifo which is 
			written by client. This program is written for BSD4.3
	comments send to :vikaskaranth@hotmail.com
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <linux/stat.h>

 //FIFO is created in current working directory
#define FIFO_FILE       "MYFIFO" 

int main(void)
{
        FILE *fp;
        char readbuf[80];
	
	system("clear");
	printf("I am server\n");
       				 /* Create the FIFO if it does not exist */
			        //umask(0);
        if(mknod(FIFO_FILE, S_IFIFO|0666, 0) != 0)
		perror("FIFO creation error in server\n");

        if((fp = fopen(FIFO_FILE, "r")) == NULL)
		perror("FIFO openning error\n");

        fgets(readbuf, 80, fp);
        printf("Server program Received string: %s\n", readbuf);
        
	fclose(fp);
	unlink(FIFO_FILE);	// to remove fifo
	_exit(0);		// waits IO to complete, POSIX std
        
	return(0);
}
  
