/*This program illustrates how protection flag of a memory mapped region is changed using mprotect system call*/

#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

static int alloc_size;
static char *memory;
void segv_handler(int signum)
{
	printf("memory accessed!\n");
	mprotect(memory,alloc_size,PROT_READ|PROT_WRITE);
}
int main()
{
	int fd;
	signal(SIGSEGV,segv_handler);

	alloc_size=getpagesize();

	fd=open("/dev/zero",O_RDONLY);
	memory=mmap(0,alloc_size,PROT_WRITE,MAP_PRIVATE,fd,0);
	close(fd);

	memory[0]=0;

	/*** making memory unwritable *****/

	mprotect(memory,alloc_size,PROT_NONE);

	/****Trying to write to allocated memory region****/

	memory[0]=1;
	/***All done unmap memory ***/

	printf("all done\n");
	munmap(memory,alloc_size);
	return 0;

}
			    							     
