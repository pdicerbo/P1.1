/* Perform the matrix-matrix multiplication; */
/* the matrix dimension can be given from command line as*/
/* ./mm_mult.x n_dim */

#include <stdio.h>
#include <stdlib.h>
#include "cblas.h"

void initialize_matrix(double*, int);
void print_matrix(double*, int);
void multiply_matrix(double*, double*, double*, int);
double calc_single_entry(double*, double*, int, int, int);

int main(int argc, char** argv){
  int ndim;
  double *A, *B, *C, *C_cblas;
  double alpha = 1., beta = 0.; 

  enum CBLAS_ORDER MyOrder;
  enum CBLAS_TRANSPOSE MyTranspose;

  MyOrder = CblasRowMajor;
  MyTranspose = CblasNoTrans;
  
  ndim = atoi(argv[1]);

  /* dinamic allocation of memory, usingo contiguous positions; */
  /* C initialized at zero */
  A = (double* )malloc(ndim * ndim * sizeof(double));
  B = (double* )malloc(ndim * ndim * sizeof(double));
  C = (double* )malloc(ndim * ndim * sizeof(double));

  C_cblas = (double* )malloc(ndim * ndim * sizeof(double));

  initialize_matrix(A, ndim);
  initialize_matrix(B, ndim);
  
  multiply_matrix(A, B, C, ndim);

  printf("\n\tCalculation using cblas_dgemm subroutine:");
  cblas_dgemm(MyOrder, MyTranspose, MyTranspose, ndim, ndim, ndim, alpha, A, ndim, B, ndim, beta, C_cblas, ndim);
  print_matrix(C_cblas, ndim);
  
  free(A);
  free(B);
  free(C);
  return 0;
}

void initialize_matrix(double* matrix, int n){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)
      matrix[ i*n + j] = (double) (i*n + j);
  }
  print_matrix(matrix, n);
}

void print_matrix(double* matrix, int n){
  int i, j;
  printf("\n\tPrinting matrix:\n\n");
  for(i = 0; i < n; i++){
    printf("\t");
    for(j = 0; j < n; j++){
      printf("%lg\t", matrix[ i*n + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void multiply_matrix(double* A, double* B, double* C, int n){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      C[i*n + j] = calc_single_entry(A, B, i, j, n); 
    }
  }
  print_matrix(C, n);
}

double calc_single_entry(double* A, double* B, int nr, int nc, int d){
  int i, j;
  double sum = 0.;
  for(i = 0; i < d; i++)
    sum += A[nr*d + i] * B[i*d + nc];
  return sum;
}
