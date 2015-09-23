A simple program to check the floating point precision behaviour with gnu and intel compiler 
and the effect of optmizations flag 

ifort:
   -mp1

gfortran
   -funsafe_math_optimizations

- Play with all possible precision 4,8,10,16
- discuss the reason behind the results
- explore gnu compiler options for math precisions (-frounding-math)
- compare with python 
