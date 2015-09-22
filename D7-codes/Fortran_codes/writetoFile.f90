! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
PROGRAM writeToFile 

   OPEN (unit = 1, file = "myfile") 
   WRITE(1,*) "Hello"
   CLOSE(1)

END PROGRAM
