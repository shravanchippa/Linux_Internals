/***************************************************************************
                     		  read.c  
                             -------------------
   	begin                : Wed Jul 23 2003
	description : Sample code to read / write from a file sample copy command
	version : 1.1

	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/


 
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

main(int argc, char * argv[])  
{
	int n,fd_src,fd_dest;
	char ch;
	if(argc != 3)
	{
		printf("Usage : copy file_src file_dst");
		exit(0);
	}
	if((fd_src = open(argv[1],0)) < 0 )	//O_RDONLY
	{
		printf(" Source file doesn't exist\n");
		exit(0);
	}	
	if((fd_dest = open(argv[2],1)) < 0 )	//O_WRONLY
	{
		printf(" Destination file doesn't exit\n");
		printf(" Creating it\n");
		fd_dest = creat(argv[2],0644);	//Create if argv[2] doesn't exist
	}		
	while(read(fd_src,&ch,1)) //Read 1 char at a time
	{
		write(fd_dest,&ch,1);  //write 1 char at a time
	}
	printf("Copy completed\n");
	
	close(fd_src);
	close(fd_dest);
}	
