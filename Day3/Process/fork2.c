/***************************************************************************
                          fork.c  -  description
                             -------------------
    begin                : Wed Jul 23 2003

	used system calls are :
 	        pid_t fork(void);
		pid_t getpid(void);
		pid_t getppid(void);

	structure used : NOne
	Discription:
		Parent process create a child process by calling fork system call.
		getpid prints process identification number.
		getppid prints parent process identification number

	version : 1.4
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
# include <sys/types.h>
# include <unistd.h>
main()
{
	pid_t pid;
	if((pid = fork()) < 0){
		perror("In fork\n");
	}
	else if (pid == 0){
		int pid2;
		printf("I am child my pid is %d\n",getpid());
		printf("my parent's pid is %d\n",getppid());
		if((pid = fork())== 0){
			printf("Child's child\n");}else {
			printf("I am parent's child")
				printf("My parent's grand child is %d\n",pid);
		}
	}
	else{
		printf("I am parent my pid is %d\n",getpid());
		printf(" my chaild's pid is %d\n",pid);
	}
	printf("HAi\n");
}
