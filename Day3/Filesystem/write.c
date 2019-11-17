/***************************************************************************
                          write.c  -  description
                             -------------------

	used system calls are :
	open(const cahr * name,int flags, mode_t mode);
	ssize_t read(int fd,void *buf,size_t size);
	ssize_t write(int fd,const void *buf,size_t size);
	structure used : NOne
	
	version : 1.2
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
 
main()
{
    int fd1, fd2,n;
    char ch[1024];
    if((fd1 = open("/etc/passwd",O_RDONLY)) == -1)
		perror("opening /etc/passwd\n");

 			//   fd2 = creat("newfile",0644); 

    if((fd2 = open("test.txt",O_CREAT|O_WRONLY|O_TRUNC,0666)) == -1)
	perror("opening test.txt\n");
    if((n = read(fd1,ch,300)) ==300)    
    n =	write(fd2,ch,n);
    printf("%d Bytes writen\n",n);
    close(fd1);
    close(fd2);
} 
