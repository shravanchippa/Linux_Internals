# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
int deamon_init(void);

main()
{
	deamon_init();
}

int deamon_init(void)
{
	pid_t pid;
	if((pid= fork()) < 0)	
		return -1;
	else if(pid > 0)
		exit(0);
	else{
		printf("%d",getpid());
		if(setsid() < 0)	perror("setsid error\n");
		chdir("/");
		close(1);
		close(2);
		close(0);
		umask(0);
		for(;;) {//sleep(5);
			printf("HAi I am daemon\n");}
	}
	//return 0;

}
