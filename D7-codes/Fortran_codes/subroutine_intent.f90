! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!

program sub1
    implicit none
    real(kind=8) :: y,z,t

    y = 2.
    z = 3. 
    call fsub(y,z,t)
    print *, "t = ", t, "z = ", z
end program sub1

subroutine fsub(x,y,f)
    implicit none
    real(kind=8), intent(in) :: x
    real(kind=8), intent(inout):: y
    real(kind=8), intent(out):: f
    f = x**2+y**2
!    x=0.5
    y=0.5
end subroutine fsub
