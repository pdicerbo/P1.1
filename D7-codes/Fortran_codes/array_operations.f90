! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program array_op


  integer, dimension(3):: a,b
  integer, dimension(4):: c
  integer, allocatable, dimension(:):: d
  real, dimension(5):: e

  a=1
  b=2
  c=3
  allocate(d(4))
  d=3
  e=3.14

  print*, a-b
  print*, a*b
!  print*, b*c
  print*, b*d
  print*, sin(e)

end program array_op
