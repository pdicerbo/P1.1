/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>

int multiply(int a, int b)
{
	int c;
 	c=a*b; 
        return c;
}

int main()
{
   int c=5;
   float d=6.7888;
   printf("Result: %d \n",multiply(c,d));
   return 0;
}
