#include <stdio.h>
#include <stdlib.h>
#include "cblas.h"

void initialize_matrix(double*, int, int, double*);
void print_matrix(double*, int, int);
void transpose_matrix(double*, double*, int, int);
void mat_product_(double*, double*, double*, int*, int*, int*);

int main(){

  double *A, *B, *C;
  double *AT, *BT, *CT;
  int row_a, col_a, row_b, col_b;
  double count = 1;

  /* initializing matrix dimension */  
  row_a = 2;
  col_a = 3;
  row_b = col_a;
  col_b = 4;

  A = (double* )malloc(row_a * col_a * sizeof(double));
  B = (double* )malloc(row_b * col_b * sizeof(double));
  C = (double* )malloc(row_a * col_b * sizeof(double));
  
  initialize_matrix(A, row_a, col_a, &count);
  print_matrix(A, row_a, col_a);
  initialize_matrix(B, row_b, col_b, &count);
  print_matrix(B, row_b, col_b);

  /* Transpose matrix */
  AT = (double* )malloc(row_a * col_a * sizeof(double));
  BT = (double* )malloc(row_b * col_b * sizeof(double));
  CT = (double* )malloc(row_a * col_b * sizeof(double));  

  transpose_matrix(A, AT, row_a, col_a);
  transpose_matrix(B, BT, row_b, col_b);

  printf("\nMaking product");

  /* CALLING FORTRAN ROUTINE */
  mat_product_(AT, BT, CT, &row_a, &col_a, &col_b);

  printf("\nProduct done calling fortran routine");
  transpose_matrix(CT, C, col_b, row_a);

  printf("\nPrinting Result:\n");
  print_matrix(C, row_a, col_b);

  cblas_dgemm(101, 111, 111, row_a, col_b, col_a, 1., A, col_a, B, col_b, 0., C, col_b);

  printf("\n\tPRINTING BLAS MATRIX\n");
  print_matrix(C, row_a, col_b);
  
  free(A);
  free(B);
  free(C);
  free(AT);
  free(BT);
  free(CT);

  return 0;
}

void initialize_matrix(double* matrix, int nr, int nc, double* count){
  int i, j;
  double tmp;
  tmp = *count;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      matrix[i*nc + j] = tmp;
      tmp += 1;
    }
  }
  *count = tmp;
}

void print_matrix(double* matrix, int nr, int nc){
  int i, j;
  printf("\n\tPrinting matrix:\n");
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++)
      printf("\t%lg", matrix[i*nc + j]);
    printf("\n");
  }
}

void transpose_matrix(double* matrix, double* transp, int nr, int nc){
  int i, j;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      transp[j*nr + i] = matrix[i*nc + j];
    }
  }
}
