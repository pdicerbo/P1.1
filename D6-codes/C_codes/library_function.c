/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

int main(int argc, char **argv)
{
	double *A, *B, *C;
    	int m, n, k, i;
   	double alpha, beta;

	m = k = n = 1000;
        alpha = 1.0; beta = 0.0;

	A = (double *)malloc( m*k*sizeof( double ));
	B = (double *)malloc( k*n*sizeof( double ));
	C = (double *)malloc( m*n*sizeof( double ));

	for (i = 0; i < (m*k); i++) 
		A[i] = (double)(i+1);
	for (i = 0; i < (k*n); i++) 
		B[i] = (double)(-i-1);
	for (i = 0; i < (m*n); i++) 
		C[i] = 0.0;
	

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
		m, n, k, alpha, A, k, B, n, beta, C, n);

	free(A);
	free(B);
	free(C);
	return 0;
}
