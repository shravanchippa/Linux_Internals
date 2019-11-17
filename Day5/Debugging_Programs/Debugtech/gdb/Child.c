#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>

main()
{
	pid_t pid;
	pid= fork();
	if(pid == 0){
		printf("this is child: PID is %d\n",getpid());
	//	sleep(30);	
		printf("parent pid is %d\n",getppid());
		printf("Terminating child \n");
	}
	else{
		printf("this is parent: PID is %d\n",getpid());
		printf("child pid is %d\n",pid);
		printf("Terminating parent \n");
	}
	return 0;
}
