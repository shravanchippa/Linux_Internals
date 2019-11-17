/***************************************************************************
                          read.c  -  description
                             -------------------

	used system calls are :
	open(const cahr * name,int flags, mode_t mode);
	ssize_t read(int fd,void *buf,size_t size);
	ssize_t write(int fd,const void *buf,size_t size);
	structure used : NOne
	Discription:
 	Sample program for cop contents from a file to another
	Open a file /etc/passwd for read mode. Open file "newfile" 
	for write mode. Read a char from filedescriptor one and write 
	into file descriptor two.
	
	version : 1.3
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


 #include<stdio.h>
 #include<sys/stat.h>
 #include<sys/types.h>
 #include<fcntl.h>
 #include<unistd.h>
 
main()
{
    int fd1, fd2,n;
    char ch;
    if((fd1 = open("/etc/passwd",O_RDONLY)) == -1)
	perror("Un able to open source");

    //creat("newfile",0644); 
    if((fd2 = open("newfile",O_CREAT|O_WRONLY|O_TRUNC,0666)) == -1)
	perror("Un able to open target");

    while((n = read(fd1,&ch,1))!= 0)    {//read one char
    	if(write(fd2,&ch,1) == -1){	//write one char
		perror("error in write");
		exit(1);
	}
    }
	for(;;);
    printf(" Copy completed\n");
    close(fd1);
    close(fd2);
} 
