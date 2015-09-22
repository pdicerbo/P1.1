program matrix_mult
  implicit none
  real, allocatable, dimension(:,:) :: A, B, C
  integer(8), parameter :: ndim = 3
  integer :: i, j
  
  allocate(A(ndim, ndim))
  allocate(B(ndim, ndim))
  allocate(C(ndim, ndim))
  
  do j = 1, ndim
     do i = 1, ndim
        A(j, i) = (i - 1)*ndim + j - 1
        B(i, j) = (i - 1)*ndim + j - 1
     end do
  end do

  C = 0
  
  print*, A
  print*, B
  print*, C

  deallocate(A, B)
  
end program matrix_mult



  
