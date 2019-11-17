/*
 * using breakpoint instruction
*/

#define BreakPoint()  __asm__ volatile("int $3");

int count;
char buf[8];
int product;

main()
{
  count=5;
  buf[0]='A';
  BreakPoint();
  display(count);
}

display(int n)
{
   product = n * 4;
}

