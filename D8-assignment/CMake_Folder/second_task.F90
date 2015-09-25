program second_task
  use iso_c_binding
  implicit none
  real(8), allocatable, target :: A(:,:), B(:,:), C(:,:)
  integer(c_int) :: row_a, col_a, row_b, col_b
  integer :: i, j
  real(8) :: count

#ifndef CBLASFOUND  
  interface
     subroutine mm_multiply(A, B, C, m, n, k) BIND(C)
       use iso_c_binding
       type(c_ptr), value :: A, B, C
       integer(c_int), value :: m, n, k
     end subroutine mm_multiply
  end interface
#endif
  
  row_a = 2
  col_a = 3
  row_b = col_a
  col_b = 4
  count = 1

  allocate(A(row_a, col_a), B(row_b, col_b), C(row_a, col_b))

  do i=1, row_a
     do j=1, col_a
        A(i, j) = count
        count = count + 1
     end do
  end do

  do i = 1, row_b
     do j=1, col_b
        B(i, j) = count
        count = count + 1
     end do
  end do

  write(*,*)
  write(*,*) "Printing first matrix:"
  print*, A
  write(*,*)
  write(*,*) "Printing second matrix:"
  print*, B
  write(*,*)

#ifndef CBLASFOUND
  call mm_multiply(c_loc(A), c_loc(B), c_loc(C), row_a, col_a, col_b);
  write(*,*) "Printing product matrix using C routine:"
  print*, C
#else  
  call dgemm('n', 'n', row_a, col_b, col_a, 1.0d+0, A, row_a, B, row_b, 0.0d+0, C, row_a)
  write(*,*) "Printing product matrix using BLAS routine:"
  print*, C
#endif
  
  deallocate(A, B, C)
  
end program
