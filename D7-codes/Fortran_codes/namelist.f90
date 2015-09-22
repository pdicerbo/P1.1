program namelist
   implicit none

   character(20) :: name
   character(20) :: surname
   integer :: age

   namelist /person/ surname,name,age

   open(unit=10	,file="data.dat")
   read(10,NML=person)
   close(unit=10)

   write(*,*) name
   write(*,NML=person) 

   name = 'Piero'

   open(unit=10 ,file="data2.dat")
   write(10,NML=person)
   close(10)
   

end program
