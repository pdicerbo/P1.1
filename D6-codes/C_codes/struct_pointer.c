/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>

typedef struct point
{
int x;
int y;
} point_t;

int main()
{
 point_t a,*pa;
 a.x=1;
 a.y=2;
 pa=&a;
 pa->x=4;
 printf("%d %d \n",a.x,pa->y);
 return 0;
}
