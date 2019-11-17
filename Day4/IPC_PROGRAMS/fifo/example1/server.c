/*****************************************************************************
Module name: server.c
Description: fifo is created and opened for read mode this process will be
	     waiting in block mode.
# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using fifo
******************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define  	FIFO_FILE	"myfifo"

main()
{
	FILE	*fp;
	char	buff[1024];

	if(mkfifo(FIFO_FILE,0666) == -1)perror("In server mkfifo");

	fp = fopen(FIFO_FILE,"r");
	fgets(buff,80,fp);
	printf("recived string%s\n",buff);

	fclose(fp);

	//unlink(FIFO_FILE);
}

