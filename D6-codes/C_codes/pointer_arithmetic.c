/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include<stdio.h>

int main() {
  
   int arr[8]; 
   int *p,*q;
   int i; 

   for (i=0;i<8;i++)
	{
	arr[i]=i;
	}	

   p=&arr[0];
	
   q=p+3;
   printf("%p %p %d \n", &arr[0], q,*q);
}
