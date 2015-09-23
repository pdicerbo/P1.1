subroutine mat_product(A, B, C, nr_a, nc_a, nc_b)
  integer, dimension(nr_a*nc_a), intent(in) :: A
  integer, dimension(nc_a*nc_b), intent(in) :: B
  integer, dimension(nr_a*nc_b), intent(in) :: B
  integer :: nr_a, nc_a, nc_b

  integer :: i, j, k
  integer :: tmp_sum = 0

  do j = 1, nc_b
     do i = 1, nr_a
        do k = 1, nc_a
           tmp_sum = tmp_sum + A(i, k) * B(k, j)
        end do
        C(i, j) = tmp_sum
        tmp_sum = 0
     end do
  end do
end subroutine mat_product
