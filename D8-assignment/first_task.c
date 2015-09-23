#include <stdio.h>
#include <stdlib.h>

void initialize_matrix(int*, int, int, int*);
void print_matrix(int*, int, int);
int* transpose_matrix(int*, int*, int, int);

int main(){

  int *A, *B, *C;
  int *AT, *BT, *CT;
  int row_a, col_a, row_b, col_b;
  int count = 1;

  /* initializing matrix dimension */  
  row_a = 2;
  col_a = 5;
  row_b = col_a;
  col_b = 5;

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

  AT = transpose_matrix(A, AT, row_a, col_a);
  print_matrix(AT, col_a, row_a);
  return 0;
}

void initialize_matrix(int* matrix, int nr, int nc, int* count){
  int i, j, tmp;
  tmp = *count;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      matrix[i*nc + j] = tmp;
      /* printf("\t%d\t%d\t%d\n", i, j, tmp); */
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

int* transpose_matrix(int* matrix, int* transp, int nr, int nc){
  int i, j;
  for(i = 0; i < nr; i++){
    for(j = 0; j < nc; j++){
      transp[j*nr + i] = matrix[i*nc + j];
    }
  }
  return transp;
}
