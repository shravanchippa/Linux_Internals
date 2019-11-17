# include <fcntl.h>
# include <unistd.h>
/*
main()
{
	int fd, i;
	fd = open("locktest",O_WRONLY|O_APPEND|O_CREAT, 0666);
		for(i = 0; i < 200000;i++)
			write(fd,"B",1);
}*/

main()
{
	int fd, i;
	fd = open("locktest",O_WRONLY|O_APPEND|O_CREAT, 0666);
	lockf(fd,F_LOCK,0);
		for(i = 0; i < 20000;i++)
			write(fd,"B",1);
}
