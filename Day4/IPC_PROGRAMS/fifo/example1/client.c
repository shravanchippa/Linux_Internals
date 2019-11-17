/**************************************************************************
	Program name: cllient.c
	Description: Thic clien opens fifo for write mode and puts some data 
		     into fifo. server which is waiting in the back ground 
		     read from fifo and prints the read contents to stdout
# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using fifo
***************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define  	FIFO_FILE	"myfifo"

main(int argc, char  *argv[])
{
	FILE	*fp;
	char	buff[1024];

	if(argc!=2){
		printf("usage fifo_client <string>\n");
		exit(0);
	}
	if((fp = fopen(FIFO_FILE,"a")) == NULL){
		printf("client: file open error\n");
		exit(1);
	}
	if(fputs(argv[1],fp)== NULL)perror("error");
	fclose(fp);
}
