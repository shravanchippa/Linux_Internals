#include <stdlib.h>

int f();

int main()
{
  f();
  return 0;
}

int f()
{
  char *ptr;
  
  ptr = malloc(1024);
  *ptr = 'A';
  free(ptr);

  return 0;
}

