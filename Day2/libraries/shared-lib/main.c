#include <stdio.h>
#include "util.h"

int main()
{
    printf("Inside main()\n");

    /* use a function from each object file that is in the library */
    util_net();
    util_file();

    return 0;
}
