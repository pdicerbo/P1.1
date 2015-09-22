D7-exercise
============

1. Write a fortran code that computes a matrix-matrix multiplication.

	- The matrices should be dynamically allocated.
	- The matrix-matrix multiplication routine should be enclosed in a function, and the function will be called by the main program
	- You can fill the matrix with integers, using an indexing such as

	  1 2 3

          4 5 6 

	  7 8 9

2. Substitute your routine with a blas_dgemm ( Fortran stores the matrices in col-major order) 

3. (optional) Check execution time of the multiplication routine while switching the loop order.
