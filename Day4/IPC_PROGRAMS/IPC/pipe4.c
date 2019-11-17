#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int data;
	char buffer[BUFSIZ + 1];
	int file_descriptor;
	
	memset(buffer,'\0',sizeof(buffer));
	sscanf(argv[1],"%d",&file_descriptor);
	data = read(file_descriptor,buffer,BUFSIZ);
	
	printf ("%d--read %d bytes: %s\n",getpid(),data,buffer);
	exit(EXIT_SUCCESS);
}
