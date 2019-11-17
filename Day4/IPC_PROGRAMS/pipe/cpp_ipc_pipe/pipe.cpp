/*
*/

# include <iostream>
# include <cstdio>
# include <unistd.h>
# include <sys/types.h>
using namespace std;
enum { READ, WRITE };

main()
{
	int	pfd[2];
	if(pipe(pfd) == -1){
		perror("error in creating pipe\n");
		_exit(9);
	}
	switch(fork()){
		case -1:
			perror("Fork error\n");
			_exit(8);
		case 0:
			dup2(pfd[WRITE], fileno(stdout));
			close(pfd[READ]);
			close(pfd[WRITE]);
			execl("/usr/bin/last","last",(char *) 0);
			break;
		default: 
			dup2(pfd[READ], fileno(stdin));
			close(pfd[READ]);
			close(pfd[WRITE]);
			execl("/bin/sort","sort",(char *) 0);
			break;
	}
}
			
