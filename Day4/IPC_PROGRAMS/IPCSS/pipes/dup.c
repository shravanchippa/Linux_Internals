#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int pfds[2];

  if ( pipe(pfds) == 0 ) {

    if ( fork() == 0 ) {

      close(1);   /*close normal stdout*/
      dup2( pfds[1], 1 );	/*make stdout same as pfds[1]*/
      close( pfds[0] );       /*we don;t need this*/
      execlp( "ls", "ls", "-1", NULL );

    } else {

      close(0);                /*close normal stdin*/
      dup2( pfds[0], 0 );      /*make stdin same as pfds[0]*/   
      close( pfds[1] );	        /*we don;t need this*/			
      execlp( "wc", "wc", "-l", NULL );

    }

  }

  return 0;
}
