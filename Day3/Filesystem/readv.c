# include<stdio.h>
# include <fcntl.h>
# include <sys/uio.h>

struct emp{
	char name[25];
	int age;
	float  sal;
}obj[2], Emp [2]={{"Hello",10,123.345},{"World",20,234.567}};

main()
{
	struct iovec  readiovobj,ioobj;
	int fd;
	int retval;
	ioobj.iov_base = Emp;
	ioobj.iov_len =sizeof(Emp);

	printf("%d",ioobj.iov_len );

	fd = open("temp",O_CREAT|O_RDWR,0666);
	retval=writev(fd,&ioobj,1);
	printf("%d",retval);

	lseek(fd,0,SEEK_SET);
	readiovobj.iov_base = obj;
	readiovobj.iov_len =sizeof(Emp);
	retval=readv(fd,&readiovobj,1);
	printf("%d",retval);
}
