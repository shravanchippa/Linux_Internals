#include <stdio.h>
//#include <mcheck.h>
#include <stdlib.h>

main ()
{
	int *a;
	char *b;
//	mtrace();
	a= (int *) malloc(4 * sizeof(int));
	b = (char *) malloc( 2 * sizeof(char));
	printf ("Memory allocated\n");
//	free(b);
	free(a);
}
