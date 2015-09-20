/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2015
 */
#include <stdio.h>
typedef enum week{ 
	sunday, 
	monday, 
	tuesday, 
	wednesday, 
	thursday, 
	friday, 
	saturday
} week_t;

int main(){
    week_t today;
    today=wednesday;
    printf("%d day",today+1);
    return 0;
   }
