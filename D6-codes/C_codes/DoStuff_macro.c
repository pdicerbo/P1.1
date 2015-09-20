/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */

#include <stdio.h>

void dostuff()
{
#ifdef MYDEF
    printf("I do other stuff, ");
#else
    printf("I do stuff, ");
#endif
}

int main()
{
   dostuff();
   printf("meet people\n");
   return 0;
}

