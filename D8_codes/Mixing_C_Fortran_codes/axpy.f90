! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
! to be used in conjunction with call_axpy.c
! gfortran -c axpy.f90
! gcc call_axpy.c axpy.o

subroutine Axpy(n,a, arr1, arr2,arr3)
  integer,intent(in) :: n,a 
  integer, dimension(n), intent(in) :: arr1, arr2
  integer, dimension(n), intent(out) :: arr3

  arr3=a*arr1+arr2
  
end subroutine Axpy
