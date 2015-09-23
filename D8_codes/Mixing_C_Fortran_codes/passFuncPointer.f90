! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
! to be used in conjunction with funcPointer.c
! gcc -c funcPointer.c
! gfortran passFuncPointer.f90 funcPointer.o

program passFuncPointer
  use iso_c_binding
  implicit none
  interface
     integer function execute(a,b, op) bind(C)
           use iso_c_binding
           integer, value :: a,b       
           type(c_funptr), value :: op
     end function execute
  end interface

  integer :: a,b
  type(c_funptr) :: fptr1
  a=1
  b=2
  fptr1=c_funloc(minus)
  print*, execute(a,b, c_funloc(plus))
  print*, execute(a,b, fptr1)

  contains
  integer function plus(a,b)
      integer, value :: a,b
      plus=a+b
  end function plus   

  integer function minus(a,b)
      integer, value :: a,b
      minus=a-b
  end function minus

end program

