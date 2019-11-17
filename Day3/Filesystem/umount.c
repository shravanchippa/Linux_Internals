#include<sys/mount.h>

main()
{
	int ret;
	ret = umount ("/mnt/floppy");
	if(ret != -1)
	{
		printf(" Unmounting successful\n");
	}
}
