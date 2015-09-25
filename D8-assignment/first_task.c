#include <stdio.h>
#include <stdlib.h>
#include "cblas.h"

void initialize_matrix(int*, int, int, int*);
void print_matrix(int*, int, int);
void transpose_matrix(int*, int*, int, int);
void mat_product_(int*, int*, int*, int*, int*, int*);
void initialize_Dmatrix(double*, int, int, int*);
void print_Dmatrix(double*, int, int);

int main(){

  int *A, *B, *C;
  int *AT, *BT, *CT;
  double *AD, *BD, *CD;
  int row_a, col_a, row_b, col_b;
  int count = 1;

  /* initializing matrix dimension */  
  row_a = 2;
  col_a = 3;
  row_b = col_a;
  col_b = 4;

  A = (int* )malloc(row_a * col_a * sizeof(int));
  B = (int* )malloc(row_b * col_b * sizeof(int));
  C = (int* )malloc(row_a * col_b * sizeof(int));
  
  initialize_matrix(A, row_a, col_a, &count);
  print_matrix(A, row_a, col_a);
  initialize_matrix(B, row_b, col_b, &count);
  print_matrix(B, row_b, col_b);

  /* Transpose matrix */
  AT = (int* )malloc(row_a * col_a * sizeof(int));
  BT = (int* )malloc(row_b * col_b * sizeof(int));
  CT = (int* )malloc(row_a * col_b * sizeof(int));  

  transpose_matrix(A, AT, row_a, col_a);
  transpose_matrix(B, BT, row_b, col_b);

  printf("\nMaking product");

  /* CALLING FORTRAN ROUTINE */
  mat_product_(AT, BT, CT, &row_a, &col_a, &col_b);

  printf("\nProduct done calling fortran routine");
  transpose_matrix(CT, C, col_b, row_a);

  printf("\nPrinting Result:\n");
  print_matrix(C, row_a, col_b);

  printf("\n\tUsing CBLAS library\n");
  AD = (double* )malloc(row_a * col_a * sizeof(double));
  BD = (double* )malloc(row_b * col_b * sizeof(double));
  CD = (double* )malloc(row_a * col_b * sizeof(double));

  count = 1;
  initialize_Dmatrix(AD, row_a, col_a, &count);
  initialize_Dmatrix(BD, row_b, col_b, &count);
  
  cblas_dgemm(101, 111, 111, row_a, col_b, col_a, 1., AD, col_a, BD, col_b, 0., CD, col_b);

  printf("\n\tPRINTING BLAS MATRIX\n");
  print_Dmatrix(CD, row_a, col_b);
  
  free(A);
  free(B);
  free(C);
  free(AT);
  free(BT);
  free(CT);
  free(AD);
  free(BD);
  free(CD);
  return 0;
}

void initialize_matrix(int* matrix, int nr, int nc, int* count){
  int i, j, tmp;
  tmp = *count;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      matrix[i*nc + j] = tmp;
      tmp += 1;
    }
  }
  *count = tmp;
}

void print_matrix(int* matrix, int nr, int nc){
  int i, j;
  printf("\n\tPrinting matrix:\n");
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++)
      printf("\t%d", matrix[i*nc + j]);
    printf("\n");
  }
}

void initialize_Dmatrix(double* matrix, int nr, int nc, int* count){
  int i, j, tmp;
  tmp = *count;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      matrix[i*nc + j] = (double) tmp;
      tmp += 1;
    }
  }
  *count = tmp;
}

void print_Dmatrix(double* matrix, int nr, int nc){
  int i, j;
  printf("\n\tPrinting double matrix:\n");
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++)
      printf("\t%lg", matrix[i*nc + j]);
    printf("\n");
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
