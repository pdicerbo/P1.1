program second_task
  use iso_c_binding
  implicit none
  integer(c_int), allocatable, dimension(:,:), target :: A, B, C
  integer(c_int) :: row_a, col_a, row_b, col_b, count
  integer :: i, j
  
  row_a = 2
  col_a = 2
  row_b = col_a
  col_b = 2
  count = 1

  allocate(A(row_a, col_a), B(row_b, col_b), C(row_a, col_b))

  do j=1, col_a
     do i=1, row_a
        A(i, j) = count
        count = count + 1
     end do
  end do

  do j=1, col_b
     do i=1, row_b
        B(i, j) = count
        count = count + 1
     end do
  end do

  print*, A
  print*, B
  
end program
