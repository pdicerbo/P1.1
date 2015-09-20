/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>

int main(){

    union data{
    int idata;
    char sdata;	
    } x;
 
 
    x.idata=65;
    printf("%d %c \n",x.idata, x.sdata );
    return 0;
   }
