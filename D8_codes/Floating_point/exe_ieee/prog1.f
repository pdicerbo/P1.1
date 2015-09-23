      program main1
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
      
      end


      subroutine xaver( a, mx )
c
c  Average the data in i direction.
c
      implicit none
      integer mx
      real a(mx)
      integer i
      
      do i = 1, mx-1
         a(i) = ( a(i) + a(i+1) ) / 2.
      end do

      end

