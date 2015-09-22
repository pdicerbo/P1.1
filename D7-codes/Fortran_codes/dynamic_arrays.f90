! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program test

INTEGER, ALLOCATABLE, DIMENSION(:) :: a
INTEGER, ALLOCATABLE, DIMENSION(:,:) :: b
INTEGER :: n,m

n=10
m=5
ALLOCATE(a(n),b(-n:m,n))

  print*, size(a)
  print*, size(b)
  print*, size(b,1)
  print*, size(b,2)


DEALLOCATE(a,b)

end program test
