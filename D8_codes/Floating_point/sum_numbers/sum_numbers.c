#include <stdlib.h>
#include <stdio.h>
#include <math.h>

main()
{
  float directly,reversly;
  float gauss_formula_float;
  int nsteps,i,ilarge,k,i_dir,i_rev;
  int gauss_formula_int;
  
  printf("# enter N: ");
  scanf("%d",&nsteps);
  
  i_rev=0;
  i_dir=0;
  directly=0.0;
  reversly=0.0;

  for(i=1;i<=nsteps;i++){
    i_dir+=i;
    ilarge=nsteps+1-i;
    i_rev+=ilarge;
    directly+=((float)i);
    reversly+=((float)ilarge);
  }
  
  k=nsteps;
  gauss_formula_float=(((float) k)*((float) k+1))/2.0;
  gauss_formula_int=(k*(k+1))/2;

  printf("#the mathematical correct result:[n*(n+1)/2]=\n");
  printf("%20d  %25.15lf\n",gauss_formula_int,gauss_formula_float);
  printf("#summing integers: direct  and reverse\n");
  printf("%20d   %20d\n",i_dir,i_rev);
  printf("#summing floating point  numbers: direct and reverse\n");
  printf("%25.15lf   %25.15lf\n",directly,reversly);
  printf("#differences among integers and floats absolute values:direct and reverse\n");
  printf("%25.15lf   %25.15lf\n", fabs(directly-((float) i_dir)),reversly-((float) i_rev));

}
