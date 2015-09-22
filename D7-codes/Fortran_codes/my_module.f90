! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
module my_module
  
   implicit none 
   integer,parameter :: a=3

   contains

   subroutine plusone(a)
   integer, intent(inout) ::a
   a=a+1
   end subroutine

end module 
