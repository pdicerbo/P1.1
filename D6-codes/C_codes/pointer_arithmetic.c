/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include<stdio.h>

int main() {
  
   int arr[8]; 
   int *p,*q;
   int i; 

   float d_arr[8]; 
   float *d_p,*d_q;
   /* int i;  */

   
   for (i=0;i<8;i++)
	{
	arr[i]=i;
	}	

   p=&arr[0];
	
   q=p+3;
   printf("%p %p %d \n", &arr[0], q,*q);


   for (i=0;i<8;i++)
	{
	  d_arr[i]=0.1 + i;
	  printf("%d\td_arr[%d] = %g\n",i, i, d_arr[i]);
	}	

   d_p=&d_arr[0];
	
   d_q= d_p + 3;
   printf("\tdouble:\n\t%p %p %g \n", &d_arr[0], d_q,*d_q);

   
}
