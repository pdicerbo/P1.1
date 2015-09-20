/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>


int main (int argc, char ** argv)
{

   int n;
   if (argc<2)
	{
	printf(" Usage: %s (number) \n",argv[0]);
	return 1;
	}
   
   n=atoi(argv[1]);
   printf(" Awesome code that reads %d from command line! \n",n);
   return 0;
}
