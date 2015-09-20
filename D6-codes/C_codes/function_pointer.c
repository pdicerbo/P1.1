/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>

double square(double x)
  {
     return x*x;
  }

double cube(double x)
  {
     return x*x*x;
  }

double area(double (*MyFunc)(double x), int num)
	{
	int i;
	double sum=0.0;
	double dx=1.0/num;
	for (i=0;i<num;i++)
		{
		sum+=MyFunc((i+0.5)*dx)*dx;
		}
	return sum;
	}

int main()
{
	int n=100;
	printf("Area under x^2 between 0 and 1 using %d points is %f \n",n, area(square,n));
	printf("Area under x^3 between 0 and 1 using %d points is %f \n",n, area(cube,n));
}
