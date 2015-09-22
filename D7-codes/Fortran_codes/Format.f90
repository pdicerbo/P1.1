! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
PROGRAM FortranFormat 

INTEGER :: a = 12345678,b,c,d 
CHARACTER(30) :: FMT1

b=a
c=a
d=a

5 FORMAT (2(I3, 1X), 2(I8, 1X))
WRITE(*,5)  a,b,c, d 

FMT1="(2(I3, 1X), 2(I8, 1X))"

WRITE(*,FMT1)  a,b,c, d

END PROGRAM
