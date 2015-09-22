! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program factorial
   implicit none
   integer :: n=10, fac   
   print*, fac(n)


end program factorial

recursive function fac(n) result(r)
   implicit none 
   integer :: n,r

   if (n==1 .or. n==0) then
      r=1
   else
      r=n*fac(n-1)
   end if
   
end function fac
