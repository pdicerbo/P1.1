/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 *
 * to be used in conjunction with axpy.f90
 * gfortran -c axpy.f90
 * gcc call_axpy.c axpy.o
 */

#include <stdio.h>

void axpy_(int*, int*, int*, int*, int*); 
void print_version(void);

int main(){

  int n=10,alpha=3;
  int a[10],b[10],c[10];
  int i;

  for (i=0;i<n;i++)
      {
      a[i]=1;
      b[i]=2;
      }

  print_version();
#ifdef DEBUG
  printf(" Callling f90 axpy with arrays of size %d \n", n);
#endif 
  axpy_(&n,&alpha,a,b,c);
  for (i=0;i<n;i++)
      {
      printf(" %d | ",c[i]);
      }    
  printf("\n");
 
  return 0;
}
