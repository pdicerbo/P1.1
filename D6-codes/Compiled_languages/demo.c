#include <stdio.h>
#include <math.h>

/* a demo code to show few thing about compilation, preprocessors and linking 
  Prepared by S. Cozzini and G.P.Brandino for the MHPC- P1.1 module */
int main ()  {

 float x=4;
 float f=sin(x);
#ifdef DEBUG 
 printf("sin(x) is %f ",f); 
#endif
return 0;
}

