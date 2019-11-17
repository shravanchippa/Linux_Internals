#include<stdlib.h> 
#include<stdio.h> 
#include<unistd.h>
# include <fcntl.h>
main()
{
	int fd, n;
	char buff[1024];
	static int val = 0;
	fd = open("/usr/include/stdio.h",O_RDONLY,0);
	while((n = read(fd,buff,1024))){
		write(1,buff,n); val++;
		}
		printf( "val = %d",val);
}
