#include <stdio.h>

int static_library_function(char *msg)
{
	printf("\nMessage from the static library\n");
	printf("%s\n", msg);
	printf("=================================\n");
	return 0;
}
