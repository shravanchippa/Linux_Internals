/***************************************************************************
                     		  dup2.c  
                             -------------------
   	begin                : Wed Jul 23 2006
	system calls used: 
		int creat(const char *pathname,mode_t mode);
		int dup2(int oldfd, int newfd);
		oldfd and newfd share file locks, file position pointers
		and falgs. 

	description : dup creates the copy of the file decriptor oldfd, 
		returns new fd in success, -1 in error
	version : 1.2
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

main()
{
	int fd, newfd;
	system("clear");

	if((fd = creat("testfile",0666)) == -1){
		perror("Creat failed\n");
		exit(0);
	}
	printf("Descriptor is %d",fd);
	newfd= dup2(fd,5);//requesting 5 as new file descriptor
	printf("\nNew Descriptor is %d\n",newfd);
	printf("The PID is %d\n",getpid());
	for(;;);
	close(fd);
	close(newfd);
}
