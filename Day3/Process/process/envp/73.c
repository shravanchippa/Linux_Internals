	#include <stdio.h>

	extern **environ;
	int main ()
	{
		int i;
		for(i=0;environ[i];i++)
		printf ("%s\n",environ[i]);
	}
