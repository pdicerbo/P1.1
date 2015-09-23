D8 -Assignment
==============

Write a matrix-matrix multiplication code, mixing C and Fortran 90

- first, write a fortran 90 procedure to compute the matrix-matrix multiplication. Then write a c code that allocates and fills the matrices, calls the fortran routine, and then prints the resulting matrix.
  Allocation should be dynamic. Remember to keep into account the row-major/col-major storage differences
  To test the code use matrices such as 

  1 2 3  |  10 11 12
         |
  4 5 6  |  13 14 15
         |
  7 8 9  |  16 17 18 

  This because such matrices would give different results if you don't keep into account row-major/col-major order.
- second, do the other way around: the matrix-matrix multiplication routine in C and the program in Fortran 90, using iso_c_binding
- third, beside your implementation, use a blas_dgemm
- optional: provide a makefile with the two targets
- optional: compare the timing of the different versions
