#include<stdio.h>
#include<mcheck.h>

int fun(void);

main()
{
	int *a;
	mtrace();
	fun();
	a=(int *)malloc(4*sizeof(int));
	//free(a);
}

int fun(void)
{
	char *b;
	b=(char *)malloc(2*sizeof(char));
	//free(b);
}	

