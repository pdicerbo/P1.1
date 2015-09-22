! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program useDDT

   implicit none
   type mytype
     integer:: i
     real*8 :: a(3)
   end type mytype


   type (mytype)  a 

   a%i=3
   a%a=1.0

   print*, a%i, a%a

end program
