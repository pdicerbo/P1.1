      program main2
c
c  
c
      implicit none
      integer mx
      parameter( mx = 1000000 )
      real a(mx)

      integer i

      ! Initialize the array
      
      do i = 1, mx
         a(i) = real(i)
      end do
      
      ! Average the array
      do i = 1, 1000
      	 call xaver( a, mx )
      end do
      print*, a(1000)    
      end


      subroutine xaver( a, mx )
c
c  Average the data in i direction.
c
      implicit none
      integer mx
      real a(mx)
      integer i
      
      do i = 1, mx-2
         a(i) = ( a(i) + a(i+1) + a(i+2)  ) / 3.
      end do

      end

