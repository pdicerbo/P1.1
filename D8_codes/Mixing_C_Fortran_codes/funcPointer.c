/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 *
 * to be used in conjunction with passFuncPOinter.f90
 * gcc -c funcPointer.c
 * gfortran passFuncPointer.f90 funcPointer.o 
 */


int  execute( int a, int b, int (*op) ( int ,int))
{
     return op(a,b);
}


