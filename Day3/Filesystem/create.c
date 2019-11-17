/***************************************************************************
                     		  creat.c  
                             -------------------
   	begin                : Wed Jul 23 2006
	description : Sample code to read / write from a file sample copy command
	version : 1.1
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

main()
{
	int fd;
	system("clear");

	//equal to open("testfile",O_CREAT|O_WRONLY|O_TRUNC,0666)
	if((fd = creat("testfile",0666)) == -1){
		perror("Creat failed\n");
		_exit(0);
	}
	//Writing to file

	printf("FILE DESCRIPTOR IS %d\n",fd);
	write(fd,"Testing .........!",15);
	close(fd);
}
