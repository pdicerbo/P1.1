/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>
#include <stdlib.h>


void fill_array(int n)
         {
         int i;
         double * a;
         a=(double*)malloc(n*sizeof(double));

         for (i=0;i<n; i++)
             {
             a[i]=i;
             }
         }


int main ( )
{
	int i,n=1000000, m=10;
        for (i=0;i<m;i++)
		{
		sleep(1);
		fill_array(n);
		}
	return 0;
}
