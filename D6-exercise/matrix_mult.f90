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
  
  call matrix_multiply(A, B, C, ndim)
  
  print*, A
  print*, B
  print*, C

  ! call print_matrix(C, ndim)

  deallocate(A, B)
  
end program matrix_mult

subroutine matrix_multiply(A, B, C, n)
  implicit none
  integer(8), intent(in) :: n
  real, intent(in) :: A(n, n)
  real, intent(in) :: B(n, n)
  real, intent(inout) :: C(n, n)
  
  integer(8) :: i, j, k
  real :: tmp_sum = 0
  
  do j = 1, n
     do i = 1, n
        do k = 1, n
           tmp_sum = tmp_sum + A(i, k) * B(k, j)
        end do
        C(i, j) = tmp_sum
        tmp_sum = 0
     end do
  end do

end subroutine matrix_multiply

subroutine print_matrix(A, n)
  implicit none
  integer(8), intent(in) :: n
  real, intent(in) :: A(n, n)

  integer(8) :: i, j
  
  do i = 1, n
     do j = 1, n
        print*, A(i, j)
     end do
     write(*,*) " "
  end do
end subroutine print_matrix
