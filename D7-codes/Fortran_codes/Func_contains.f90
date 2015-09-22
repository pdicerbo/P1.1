! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!

PROGRAM FUNC_CONTAINS 
 IMPLICIT NONE

INTEGER:: i,n = 10, r

DO i=1,n,1 
   r=Addme(i,n)
   WRITE(*,*) i,n,r 
END DO

CONTAINS
INTEGER FUNCTION Addme(a,b)
  IMPLICIT NONE
  INTEGER :: a,b
   Addme = a + b
END FUNCTION 

END PROGRAM
