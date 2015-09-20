/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>
#include <stdlib.h>

void fillInt(int *p) ;

int main()
{
   int *p;
   fillInt(p);
   printf("%d \n",*p);
   return 0;
}

void fillInt(int *p)
{
     int a=5; 
     p=&a;
}

