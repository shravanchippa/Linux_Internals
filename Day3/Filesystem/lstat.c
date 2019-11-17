/***************************************************************************
                          lstat.c  -  description
//                             -------------------
/// /*    begin                : Wed Jul 23 2006
	used system calls are :
	lstat(const char *pathname, struct stat *buff);
	in case of symbolic link link itself will be stated
	structure used :
		struct is defined in fstat.c
	Discription:
	Sample code to get the inode info of a file
	version : 1.3
	Author : vikaskaranth@gmail.com

//	struct stat {
//	      dev_t     st_dev;     /* ID of device containing file */
//	      ino_t     st_ino;     /* inode number */
//	      mode_t    st_mode;    /* protection */
//	      nlink_t   st_nlink;   /* number of hard links */
//	      uid_t     st_uid;     /* user ID of owner */
//	      gid_t     st_gid;     /* group ID of owner */
//	      dev_t     st_rdev;    /* device ID (if special file) */
//	      off_t     st_size;    /* total size, in bytes */
//	      blksize_t st_blksize; /* blocksize for filesystem I/O */
//	      blkcnt_t  st_blocks;  /* number of blocks allocated */
//	      time_t    st_atime;   /* time of last access */
//	      time_t    st_mtime;   /* time of last modification */
//	      time_t    st_ctime;   /* time of last status change */
//	 }; */
//

// *   it under the terms of the GNU General Public License as published by  *
// *   the Free Software Foundation; either version 2 of the License, or     *
// *   (at your option) any later version.                                   *
// ************************************************************************** */ *//

# include <stdio.h>
#include<sys/stat.h>
main(int argc, char* argv[])
{
	struct stat fst;

	system("ln -s argv[1] lnfile");//creating symbolic link

	lstat("lnfile",&fst);//finding the status of the link

	printf("Listing the detailsd of the file\n");
	printf(" The inode no of the file is %d\n",fst.st_ino);
	printf(" The device of the file is %d\n",fst.st_dev);
	printf(" The block size of the file system is %d\n",fst.st_blksize);
	printf(" The last accessed time of the file is %d\n",fst.st_atime);
}	
