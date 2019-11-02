#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  float a[3][4],a22,a23,a32,a33,b2,b3,a332,b32,x,y,z;
  int i = 0,j = 0;
  printf("a00x + a01y + a02z = a03\n");
  printf("a10x + a11y + a12z = a13\n");
  printf("a20x + a21y + a22z = a23\n");
  while (i != 3) {
    for (j=0;j<4;j++) {
      printf("a%d%d = ",i,j);
      scanf("%f",&a[i][j]);
    }
    i++;
  }
  a22 = a[1][1] - ((a[1][0] * a[0][1]) / a[0][0]);
  a23 = a[1][2] - ((a[1][0] * a[0][2])/ a[0][0]);
  a32 = a[2][1] - ((a[2][0] * a[0][1]) / a[0][0]);
  a33 = a[2][2] - ((a[2][0] * a[0][2]) / a[0][0]);
  b2 = a[1][3] - ((a[1][0] * a[0][3]) / a[0][0]);
  b3 = a[2][3] - ((a[2][0] * a[0][3]) / a[0][0]); 
  a332 = a33 - ((a32*a23) / a22);
  b32 = b3 - ((a32 * b2)/a22);
  z = b32 / a332;
  y = (b2 - (a23*z)) / a22;
  x = (a[0][3] - (a[0][1] * y) - (a[0][2] * z)) / a[0][0]; 
  printf("x = %f\n",x);
  printf("y = %f\n",y);
  printf("z = %f\n",z); 
}
  
