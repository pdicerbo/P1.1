/* perform C-version of matrix matrix multiplication */
#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(double*, double*, int, int);

void mm_multiply(double* A, double* B, double* C, int nr_a, int nc_a, int nc_b){

  double *A_True, *B_True, *C_True;
  int i, j, k;
  double tmp_sum = 0;
  int nr_b = nc_a;
  
  A_True = (double* )malloc(nr_a * nc_a * sizeof(double));
  B_True = (double* )malloc(nr_b * nc_b * sizeof(double));
  C_True = (double* )malloc(nr_a * nc_b * sizeof(double));
  
  transpose_matrix(A, A_True, nc_a, nr_a);
  transpose_matrix(B, B_True, nc_b, nr_b);

  for(i = 0; i < nr_a; i++){
    for(j = 0; j < nc_b; j++){
      for(k = 0; k < nc_a; k++){
	tmp_sum += A_True[i*nc_a + k] * B_True[k * nc_b + j];
      }
      C_True[i*nc_b + j] = tmp_sum;
      tmp_sum = 0;
    }
  }
  transpose_matrix(C_True, C, nr_a, nc_b);
}

void transpose_matrix(double* matrix, double* transp, int nr, int nc){
  int i, j;
  /* putting the (i, j) element of matrix in (j, i) element of transp */
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      transp[j*nr + i] = matrix[i*nc + j];
    }
  }
}
