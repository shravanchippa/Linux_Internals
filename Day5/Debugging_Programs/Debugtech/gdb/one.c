#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int myfun(char *);

int main(int argc,char *argv[])
{
	int res;	
	res=myfun(argv[1]);
	printf("number of bytes read is %d",res);
	return 0;
}

int  myfun(char *filename)
{
	
	int fd;	
	char buf[4096];
	int count=1000;
	int rd;
	fd=open(filename,O_RDWR);	
	printf("file descriptor is %d\n",fd);
	rd=read(fd,buf,count);
	printf("number of bytes read is %d\n",rd);
	printf("buf contains %s\n",buf);
	return rd;
}
