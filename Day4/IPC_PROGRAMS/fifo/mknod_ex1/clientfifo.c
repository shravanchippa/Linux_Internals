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
#define FIFO_FILE       "MYFIFO1" 

int main(int argc, char **argv)
{
        FILE *fp;

        if((fp = fopen(FIFO_FILE, "a")) == NULL)
		perror("FIFO openning error\n");

        fputs(argv[1], fp);
        
	fclose(fp);
        
	return(0);
}
  
