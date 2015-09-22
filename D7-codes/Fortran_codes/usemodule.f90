! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program usemodule 
   use my_module
   implicit none
   integer:: b

   b=1
   call plusone(b)
   print*,a,b 

end program
