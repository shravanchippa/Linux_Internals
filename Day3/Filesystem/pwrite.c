/***************************************************************************
                          pwrite.c  -  description
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
    char ch;
    if((fd2 = open("newfile",O_WRONLY,0666)) == -1){
	perror("Un able to open target");
	exit(1);
    }
    pwrite(fd2,"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",40,500); 
    pwrite(fd2,"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",40,500); 

    close(fd2);
} 
