# include <fcntl.h>
# include <unistd.h>

/*main()
{
	int fd, i;
	if((fd = open("locktest",O_CREAT|O_WRONLY|O_APPEND, 0666))< 0)
		perror("Error in opening");
	for(i = 0; i < 200000;i++)
		if(write(fd,"A",1)== -1)
			perror("write error");
}*/

main()
{
	int fd, i;
	if((fd = open("locktest",O_CREAT|O_WRONLY|O_APPEND, 0666))< 0)
		perror("Error in opening");
	lockf(fd,F_LOCK,0);
	for(i = 0; i < 20000;i++)
		if(write(fd,"A",1)== -1)
			perror("write error");
}
