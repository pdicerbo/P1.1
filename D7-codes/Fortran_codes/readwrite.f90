! Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
! Last Revision: July 2015
!
PROGRAM ReadWrite 

CHARACTER(LEN=15) :: Name
INTEGER :: phone_number

WRITE(*,*) "Hello, what's your name and phone number?"
READ(*,*) name, phone_number
WRITE(*,*) "Hello again, ",name, phone_number

END PROGRAM
