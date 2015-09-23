! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
! to be used in conjunction whit cfunc. 
! - gcc -c cfunc.c
! - gfortran usecfunc.f90 cfunc.o
program usecfunc
 use iso_c_binding
 implicit none
 interface 
   subroutine cfunc(c,d,e) bind(C)
      use iso_c_binding 
      integer(c_int), value :: c
      integer(c_int) :: d
      integer(c_int) :: e(2) 
!      type(c_ptr), value :: e  ! alternatively, you can define e as a c_ptr, but then the static array p(2) below needs to have the target attribute, 
                                ! to be to extract the C address by means of c_loc(p) 
   end subroutine
 end interface
 integer :: m,n,p(2)
! integer, target :: p(2)
 m=5
 p=1
  call cfunc(m,n,p)
! call cfunc(m,n,c_loc(p))
 print*, m,n,p(1) 

end program
