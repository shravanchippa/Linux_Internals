/*
 * mtrace
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mcheck.h> /* get the mtrace definitions */

int main()
{
    char *ptr;

    mtrace();  /* Turn on mtrace function */

    ptr = (char *)malloc(1024);

    muntrace();  /* Turn off mtrace function */

    exit(0);
}

