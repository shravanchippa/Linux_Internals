#include<stdio.h>
#include<mcheck.h>
main()
{
	int *a;
	char *b;
	mtrace();
	a=(int *)malloc(4*sizeof(int));
	b=(char *)malloc(2*sizeof(char));
	free(a);
	free(b);
}
