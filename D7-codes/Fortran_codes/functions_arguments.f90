! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
program procedure_arg
   implicit none
   integer, dimension(10) ::arr
   interface
     subroutine plusone(arr)
     integer, dimension(:), intent(inout):: arr
     end subroutine plusone
   end interface

   interface
     subroutine minusone(arr)
     integer, dimension(:), intent(inout):: arr
     end subroutine minusone
   end interface


   interface 
     integer function calculate(arr,op)
       integer, dimension(:),intent(inout) :: arr
       interface
         subroutine op(arr)
         integer, dimension(:), intent(inout):: arr
         end subroutine op
       end interface
     end function calculate
   end interface
 

   arr=1
   print*, calculate(arr,plusone) 
   print*, calculate(arr,minusone)

end program procedure_arg


integer function calculate(arr,op)
   implicit none
   integer, dimension(:),intent(inout) :: arr
   integer :: res
   integer :: i
   interface 
     subroutine op(arr)
     integer, dimension(:), intent(inout):: arr
     end subroutine op
   end interface

   call op(arr)

   res=0
   do i=1,size(arr)
      res=res + arr(i)
   end do
   calculate=res
end function calculate


subroutine plusone(arr)
   implicit none
   integer :: i
   integer, dimension(:), intent(inout):: arr
 
   arr=arr+1
end subroutine plusone


subroutine minusone(arr)
   implicit none
   integer :: i
   integer, dimension(:), intent(inout):: arr

   arr=arr-1
end subroutine minusone

