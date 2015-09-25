program second_task
  use iso_c_binding
  implicit none
  integer(c_int), allocatable, target :: A(:,:), B(:,:), C(:,:)
  integer(c_int) :: row_a, col_a, row_b, col_b, count
  integer :: i, j
  real(8), allocatable :: AR(:,:), BR(:,:), CR(:,:)
  real(8) :: rcount
  
  interface
     subroutine mm_multiply(A, B, C, m, n, k) BIND(C)
       use iso_c_binding
       type(c_ptr), value :: A, B, C
       integer(c_int), value :: m, n, k
     end subroutine mm_multiply
  end interface
  
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

  call mm_multiply(c_loc(A), c_loc(B), c_loc(C), row_a, col_a, col_b);
  
  print*, A
  print*, B
  print*, C

  allocate(AR(row_a, col_a), BR(row_b, col_b), CR(row_a, col_b))
  rcount = 1

  do i=1, row_a
     do j=1, col_a
        AR(i, j) = rcount
        rcount = rcount + 1
     end do
  end do

  do i=1, row_b
     do j=1, col_b
        BR(i, j) = rcount
        rcount = rcount + 1
     end do
  end do
  print*, AR
  print*, BR
  call dgemm('n', 'n', row_a, col_b, col_a, 1.0d+0, AR, row_a, BR, row_b, 0.0d+0, CR, row_a)
  print*, CR

  deallocate(A, B, C, AR, BR, CR)
  
end program
