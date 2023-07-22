#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Matthew Hernandez
//UCFID: 5357015
//Submitted on 9/10/21
int main()
{
    double x1,x2,y1,y2;
    printf("Enter the coordinates (x, y) of Point A:\n");
    scanf("%lf, %lf", &x1,&y1 );
    printf("Enter the coordinates (x, y) of Point B:\n");
    scanf("%lf, %lf", &x2,&y2 );

    printf("Point A: %.2f, %.2f\n",x1, y1);
    printf("Point B: %.2f, %.2f\n",x2, y2);

  double distance=sqrt((pow(x2-x1,2)+pow(y2-y1,2)));
  printf("The distance is: %.2f\n", distance);


        return 0;
}
