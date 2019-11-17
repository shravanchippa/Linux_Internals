	#include <stdio.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>


	int main ()
	{
		mkfifo("myfifo",S_IFIFO|0644);
	}
