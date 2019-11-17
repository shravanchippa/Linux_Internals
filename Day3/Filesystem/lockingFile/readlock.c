//usage of F_TEST it checks whether the file is locked or not
/*
# include <fcntl.h>
# include <unistd.h>
main()
{
	int fd, retvelue;
	pid_t pid;
	char   buff[100];

	if((fd = open("locktest",O_RDWR|O_CREAT, 0666)) == -1)
		perror("open file locktest\n");

	if(lockf(fd,F_LOCK,0) == -1)
		perror("lockf failed");

	if((pid = fork()) == 0){
		//Child is reading
		if(read(fd,buff,100) == -1)	perror("read error");
		buff[100]='\0';
		puts(buff);
		puts("The child process over");
	}
	else	{
		puts("Parent is sleeping");
		sleep(5);
		printf("Process %d is over\n",getpid());
	}
}
*/

/* Child checks for locktest since parent locked the file child continues in
loop till parent exits once file is unlocked by parent childs resumes 
to read the content of the file */

# include <fcntl.h>
# include <unistd.h>
main()
{
	int fd, retvelue;
	pid_t pid;
	char   buff[100];

	if((fd = open("locktest",O_RDWR|O_CREAT, 0666)) == -1)
		perror("open file locktest\n");

	if(lockf(fd,F_LOCK,0) == -1)
		perror("lockf failed");

	if((pid = fork()) == 0){
		//Child is reading
		for(;;){
			if(lockf(fd,F_TEST,0) == 0) {
				if(read(fd,buff,100) == -1)
					 perror("read error");
				buff[100]='\0';
				puts(buff);
				break;
			}
		}
		puts("The child process over");
	}
	else	{
		puts("Parent is sleeping");
		sleep(5);
		printf("Process %d is over\n",getpid());
	}
}
