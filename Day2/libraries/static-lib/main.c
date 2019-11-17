#include <stdio.h>

/* define external functions */
extern void util_file();
extern void util_net();

int main()
{
    printf("Inside main()\n");

    /* use a function from each object file that is in the library */
    util_file();
    util_net();

    return 0;
}
