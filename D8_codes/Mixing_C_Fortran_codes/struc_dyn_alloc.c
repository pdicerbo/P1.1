/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 * 
 * this code is supposed to be used in conjunction with usedynstruct.f90 
 * - gcc -c struc_dyn_alloc.c
 * - gfortran  usedynstruct.f90 struc_dyn_alloc.o 
 */

#include <stdio.h>

typedef struct{

   int n;
   int* a;

} myst;


void mystpr( myst a)
{
   int i;
   printf(" size %d \n content \n ", a.n);
   for (i=0;i<a.n;i++)
       {
       printf("%d \n ",a.a[i]);
       }
}
