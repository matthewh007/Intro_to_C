#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Matthew Hernandez
//UCFID: 5357015
//Submitted on 9/10/21
int main()
{
    int x1,y1;
    printf("At which yard line did the receiver catch the ball?\n ");
    scanf("%d", &x1);
    printf("How fast does the receiver run?(yards per second)\n ");
    scanf("%d", &y1);


  double distance= (double)(100-x1)/y1 ;
  printf("The receiver will score a touchdown in: %.2f seconds\n", distance);


        return 0;
}
