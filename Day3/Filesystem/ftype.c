/***************************************************************************
                          ftype.c  -  description
                             -------------------
    	date                 : Wed Jul 23 2003
	version : 1.2
	system calls used :

	lstat(const char * filename,struct stat * buff);

	 Description : To find the type of file
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *

 ***************************************************************************/

 
 #include<sys/stat.h>
 
 main(int argc, char * argv[])
 {
 	struct stat buf,rec;
	// To check file type
	lstat(argv[1], &buf);
	if(S_ISREG(buf.st_mode))
		printf("This is a regular file\n");
	else 
		printf(" this is not a regular file\n");

	// To check Directory type
	lstat("/home", &rec);
	if(S_ISDIR(rec.st_mode))
		printf("This is a Directory\n");
	else 
		printf(" this is not a directory\n");
}			
