/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 *
 * to be used in conjunction with call_axpy.f90
 * gcc -c axpy.c
 * gfortran call_axpy.f90 axpy.o
 */


void axpy(int n, int a, int* arr1, int* arr2, int* arr3)
{
  int i;
  for (i=0;i<n;i++)
      {
      arr3[i]=a*arr1[i]+arr2[i];
      }
}
