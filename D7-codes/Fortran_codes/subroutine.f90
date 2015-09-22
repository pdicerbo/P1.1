! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!

program sub1
    implicit none
    real(kind=8) :: y,z

    y = 2.
    call fsub(y,z)
    print *, "z = ",z
end program sub1

subroutine fsub(x,f)
    implicit none
    real(kind=8) :: x
    real(kind=8) :: f
    f = x**2
end subroutine fsub
