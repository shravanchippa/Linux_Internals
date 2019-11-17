/***************************************************************************
                          pread.c  -  description
                             -------------------

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
    char ch[1024];
    if((fd1 = open("/etc/passwd",O_RDONLY)) == -1)
	perror("Un able to open source");

    n = pread(fd1,ch,100,100);
    printf(ch);
    close(fd1);
} 
