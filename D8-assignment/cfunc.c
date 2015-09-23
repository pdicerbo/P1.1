#include <stdlib.h>

void transpose_matrix(int*, int*, int, int);

void mm_multiply(int* A, int* B, int* C, int nr_a, int nc_a, int nc_b){

  int *A_True, *B_True, *C_True;
  int i, j, k;
  int tmp_sum = 0;
  int nr_b = nc_a;
  
  A_True = (int* )malloc(nr_a * nc_a * sizeof(int));
  B_True = (int* )malloc(nr_b * nc_b * sizeof(int));
  C_True = (int* )malloc(nr_a * nc_b * sizeof(int));
  
  transpose_matrix(A, A_True, nc_a, nr_a);
  transpose_matrix(B, B_True, nc_b, nr_b);
  
  for(i = 0; i < nr_a; i++){
    for(j = 0; j < nc_b; j++){
      for(k = 0; k < nc_a; k++){
	tmp_sum += A_True[i*nc_a + k] * B_True[k * nc_b + j];
      }
      C_True[i*nc_b + j] = tmp_sum;
    }
  }
}

void transpose_matrix(int* matrix, int* transp, int nr, int nc){
  int i, j;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      transp[j*nr + i] = matrix[i*nc + j];
    }
  }
}
