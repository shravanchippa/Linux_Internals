#include<stdio.h>

extern char ** environ;

main()
{
	int i=0;
	while(environ[i++]!='\0')
		printf("%d\t%s\n",i,environ[i]);

}	
