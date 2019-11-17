#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

main(){
	pid_t pid;
	pid=fork();
	if(pid == 0){
		printf("I am child\n");
		exit(-1);
	}
	else{
		printf("I am parent\n");
	}
	return 0;
}

