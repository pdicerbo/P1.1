   program inverse
!a simple program to check how many inverse are not accurate.
   real*4 :: X,Y,Z
   integer:: I

   i=0
   do j=1,100,1
        X=real(j,KIND=4)
	Y=1.0/X
	Z=Y*X
	IF (Z.ne.1.0) then
	  write(*,'(A,F51.48,I4)') "this is not correct=", Z,j 
          i=i+1
	end if
   end do 
     write(*,*)"found", I 
   
   end program inverse 
