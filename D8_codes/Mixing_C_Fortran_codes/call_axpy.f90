! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
! to be used in conjunction with axpy.c
! gcc -c axpy.c
! gfortran call_axpy.f90 axpy.o


program callaxpy
  use iso_c_binding
  implicit none
  integer(c_int),allocatable,target :: arr1(:), arr2(:), arr3(:)
  integer(c_int) :: n,a

  interface 
    subroutine axpy(n,a,v1,v2,v3) BIND(C) 
        use iso_c_binding
        integer(c_int),value:: n,a
        type(c_ptr), value:: v1,v2,v3
    end subroutine axpy
  end interface

  n=10
  a=3
  allocate(arr1(n),arr2(n),arr3(n))
  arr1=1
  arr2=2

  call axpy(n,a,c_loc(arr1),c_loc(arr2),c_loc(arr3))
  print*, arr3
  deallocate(arr1,arr2,arr3)
end program
