/***************************************************************************
                          fstat.c  -  description
                             -------------------
	begin                : Wed Jul 23 2003
	version no : 1.3
	system calls used : 

	int open(const char *pathname, int flags, mode_t mode);
	int fstat(int filedes,struct stat * buff);

	structures used:

	 struct stat {
                  dev_t         st_dev;       device 
                  ino_t         st_ino;      inode 
                  mode_t        st_mode;      protection 
                  nlink_t       st_nlink;    number of hard links 
                  uid_t         st_uid;       user ID of owner 
                  gid_t         st_gid;       group ID of owner
                  dev_t         st_rdev;      device type (if inode device) 
                  off_t         st_size;      total size, in bytes 
                  blksize_t     st_blksize;   blocksize for filesystem I/O 
                  blkcnt_t      st_blocks;    number of blocks allocated 
                  time_t        st_atime;     time of last access 
                  time_t        st_mtime;     time of last modification 
                  time_t        st_ctime;     time of last change 
              };
                                                                               
	description :  Sample code to get the inode info of a file
	opened file pointed by the fstat will be state-ed
***************************************************************************/

# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include<sys/stat.h>

main()
{
	struct stat fst;
	struct tm  *Time;
	int fd;
	fd = open("testfile",O_RDONLY);
	fstat(fd,&fst);
	printf("Listing the detailsd of the file\n");
	printf(" The inode no of the file is %d\n",fst.st_ino);
	printf(" The device ID  of the file is %d\n",fst.st_dev);
	printf(" The block size of the file system is %d\n",fst.st_blksize);
	printf("The user ID is %d\n",fst.st_uid);
	printf("The group ID is %d\n",fst.st_gid);
	printf("Access time is %d\n",fst.st_atime);
	printf("creation time is %d\n",fst.st_ctime);
	printf("modification time is %d\n",fst.st_mtime);
	Time = localtime(&fst.st_atime);

	printf("day : %d\n  ",Time->tm_mday);
	printf("month: %d \n ",Time ->tm_mon);
	printf("year : %d \n ",Time->tm_year);
	printf("hour : %d \n ",Time->tm_hour);
	printf("min : %d \n ",Time ->tm_min);
}
