! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
PROGRAM Func_interface
 IMPLICIT NONE

INTEGER:: i
INTEGER, PARAMETER :: n=10
INTEGER, ALLOCATABLE :: arr(:)

INTERFACE
    INTEGER FUNCTION Addme(arr)
     IMPLICIT NONE
     INTEGER :: i, sum
     INTEGER, DIMENSION(:):: arr
    END FUNCTION
END INTERFACE

allocate(arr(10))
DO i=1,n,1
   arr(i)=i
END DO

WRITE(*,*) Addme(arr) 

END PROGRAM

INTEGER FUNCTION Addme(arr)
  IMPLICIT NONE
  INTEGER :: i,sum=0
  INTEGER, DIMENSION(:):: arr

  DO i=1,size(arr)
   sum = sum + arr(i)
  END DO
  Addme = sum
END FUNCTION

