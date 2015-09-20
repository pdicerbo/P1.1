/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>

struct
{
  unsigned int age : 3;
} Age;
int main( )
{
   Age.age = 7;
   printf( "Sizeof( Age ) : %lu\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );
   Age.age = 8;
   printf( "Age.age : %d\n", Age.age );
   return 0;
}
