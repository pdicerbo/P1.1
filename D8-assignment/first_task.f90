subroutine mat_product(A, B, C, nr_a, nc_a, nc_b)
  integer, intent(in) :: A(nr_a, nc_a)
  integer, intent(in) :: B(nc_a, nc_b)
  integer, intent(out) :: C(nr_a, nc_b)
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
