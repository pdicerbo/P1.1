/* simple program to show the role  of extended precision 
   both function overflows with gcc/icc compiler 
   Does it exist a way not to make at least squared_2 function NOT overflow ?  
  
   This examples are discussed in the following reference:
 
   The pitfalls of verifying floating-point computations
   David Monniaux  
   ACM Transactions on Programming Languages and Systems (TOPLAS)  archive
   Volume 30 ,  Issue 3 (May 2008)
   http://doi.acm.org/10.1145/1353445.1353446


S.C september 2010 
*/ 
#include <stdio.h> 
double squared_1(double v) { 

 double y = v * v;
 return (y / v); } 

double squared_2(double v) {

double x = (v * v) / v;

return x ;
} 
 
main() { 

 printf("%g\n", 1E308);
 printf("%g\n", squared_1(1E308));
 printf("%g\n", squared_2(1E308));
 }

