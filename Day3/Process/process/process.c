#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, int *argv[])
{
	int fd, pid;

	pid = fork();
	if(pid == 0)
	{
	   execl("/bin/ls", "-l", (char*)0);
	    exit(0);
	}

if (waitpid(pid) < 0)
	{
	printf("wait error\n");
	printf("%d\n", pid);
	}

pid = fork();
if (pid == 0)
{
	printf("THe PID is 0\n");

exit(0);
}

}
