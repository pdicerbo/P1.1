! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
! this code is supposed to be used in conjunction with struc_dyn_alloc.c
! - gcc -c struc_dyn_alloc.c
! - gfortran  usedynstruct.f90 struc_dyn_alloc.o 

module myMOD
   use iso_c_binding
   implicit none
   type, bind(C) :: myst
     integer(c_int) :: m
     type(c_ptr) :: p
   end type myst
end module 

program usddynst
 use iso_c_binding
 use myMOD
 implicit none

 interface 
   subroutine  mystpr (a) BIND(C)
     use iso_c_binding
     use myMOD
     type(myst),value ::a  
   end subroutine mystpr
 end interface  

 integer :: h
 integer, allocatable, target :: vec(:)
 type (myst) :: test

 h=5
 allocate(vec(h))
 vec=42
 test%m=5
 test%p=c_loc(vec)
 
 call mystpr(test)
 deallocate(vec)
end program 
