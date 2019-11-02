#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
  float a[32][32],l[32][32],u[32][32],s[32][1],z[32][1],x[32];
  int i = 0,j = 0;
  /* takes input */
  while (i != 3) {
    for (j = 0;j < 3;j++) {
      printf("a%d%d = ",i,j);
      scanf("%f",&a[i][j]);
    }
    printf("a%d3 = ",i);
    scanf("%f",&s[i][0]);
    i++;
  }
  
  for (i = 0;i < 3;i++) {
    for (j = 0;j < 3;j++) {
      if (i > j) {
        u[i][j] = 0;    /* sets all lower triangular elements to 0 */
      }
    }
  }
  for (i = 0;i < 3;i++) {
    for (j = 0;j < 3;j++) {
      if (i == j) {
        u[i][j] = 1;    /* sets all diagonal elments to 1 */
      }
    }
  }
  for (i = 0;i < 3;i++) {
    l[i][0] = a[i][0];     /* l[1][0] = a[1][0] likewise sets all first column elements as that of a */
  }
  for (i = 1;i < 3;i++) {
    u[0][i] = (a[0][i] / a[0][0]);    /* u[0][i] = (a[0][i] / a[0][0]) */
  }
  for (i = 1;i < 3;i++) {
    l[i][1] = a[i][1] - (l[i][0] * u[0][1]);    /* second row elements */
  }
  u[1][2] = (a[1][2] - (l[1][0] * u[0][2])) / l[1][1];    /* third row elements */
  l[2][2] = a[2][2] - (l[2][0] * u[0][2]) - (l[2][1] * u[1][2]); 
  for (i = 0;i < 3;i++) {
    for (j = 0;j < 3;j++) {
      if (i < j) {
        l[i][j] = 0;    /* sets all upper triangular elements to 0 */
      }
        printf("l%d%d = %f ",i,j,l[i][j]);
      
    }
    printf("\n");
  }
  printf("\n");
  for (i = 0;i < 3;i++) {
    for (j = 0;j < 3;j++) {
      printf("u%d%d = %f ",i,j,u[i][j]);
    }
    printf("\n");
  }
  /* z matrix calculation */
  z[0][0] = s[0][0] / l[0][0];
  z[1][0] = (s[1][0] - (z[0][0] * l[1][0])) / l[1][1];
  z[2][0] = (s[2][0] - (l[2][1] * z[1][0]) - (l[2][0] * z[0][0])) / l[2][2];
  /* initializing x1,x2,x3 */
  for (i = 0;i < 3;i++) {
    x[i] = 0;
  }
  for (i = 2; i >= 0; i--) {
    x[i] = z[i][0];
    for (j = 2; j > i; j--) {
      x[i] -= x[j]*u[i][j];
    }
  }
  /* prints roots */
  printf("x1 = %f\n",x[0]);
  printf("x2 = %f\n",x[1]);
  printf("x3 = %f\n",x[2]);
}  
