! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program usemodule 
   use my_module, only  : plusone
   implicit none
   integer:: a,b

   a=4
   b=1
   call plusone(b)
   print*,a,b 

end program
