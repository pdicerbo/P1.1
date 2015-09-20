/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */

#include <stdio.h>
#define pi 3.1415 
#define msg "Yo-ho!!!"
#define add(x,y) ((x)+(y))

int main()
{
  float a;
  a=pi;
  float pioneer=0.0f;
  printf (" Try to figure out where pi gets substituted, %f \n",a);
  pioneer=add(a,a);  
  printf(" %s Result : %f \n",msg,pioneer);
}
