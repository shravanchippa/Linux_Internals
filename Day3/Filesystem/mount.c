#include<sys/mount.h>
#include<stdio.h>

main()
{
	int fd;
	fd = mount("/dev/fd0","/mnt/floppy","ext2",MS_NOSUID,NULL);
	
	if(fd != -1)
	printf(" Floppy mounted successfully\n");
	printf(" Changing Directory to floppy\n");
	chdir("/mnt/floppy");
	printf(" Creating a file test_file in floppy\n");
	fd = creat("test_file",0644);
	if (fd != -1)
	printf(" File Creation successful\n");
	printf("Bye!\n");
	 
} 

