/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 *
 * to be used in conjunction whit callcfunc.f90 
 * - gcc -c cfunc.c
 * - gfortran usecfunc.f90 cfunc.o
 */

void cfunc( int a, int* b, int c[2])
{
  *b=2*a+c[0];
}
