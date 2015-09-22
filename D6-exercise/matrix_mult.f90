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
        A(i, j) = (i - 1)*ndim + j - 1
        B(i, j) = (i - 1)*ndim + j - 1
     end do
  end do

  C = 0
  
  print*, A
  print*, B
  print*, C

  call perform_multiply(A, B, C, ndim)
  
  deallocate(A, B)
  
end program matrix_mult

subroutine perform_multiply(A, B, C, n)
  implicit none
  integer(8), intent(in) :: n,
  real, intent(in) :: A(n, n)
  real, intent(in) :: B(n, n)
  real, intent(inout) :: C(n, n)
  
  integer(8) :: i, j, k
  
  do j = 1, n
     do i = 1, n
        
     end do
  end do

end subroutine perform_multiply



  
