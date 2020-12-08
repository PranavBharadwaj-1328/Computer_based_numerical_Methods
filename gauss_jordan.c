#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********To print the matrix*********/
void print(float a[32][32])
{
  int i=1 ,j;
  while (i <= 3) {
    for(j = 1;j <= 4;j++) {
      printf("%f ",a[i][j]);
    }
    printf("\n");
    i++;
  }
  printf("\n");
}
/***********Main function begins*************/
int main(int argc,char *argv[])
{
  int i,j,k,n;
  float A[32][32],c,x[31];
  if (argc != 2) {
    printf("Syntax: ./gauss_j n (n = number of variables)\n");
    exit(1);
  }
  n = atoi(argv[1]);    /* Takes n value */
  printf("Enter the equations:\n");
  printf("A[1][1]x + A[1][2]y + A[1][3]z = A[1][4]\n");
  printf("A[2][1]x + A[2][2]y + A[2][3]z = A[2][4]\n");
  printf("A[3][1]x + A[3][2]y + A[3][3]z = A[3][4]\n");
  /* Takes input */
  for (i=1; i<=n; i++) {
    for (j=1; j<=(n+1); j++) {
          printf(" A[%d][%d]:", i,j);
          scanf("%f",&A[i][j]);
    }
  }
  for (j=1; j<=n; j++) {
    for (i=1; i<=n; i++) {
      if(i!=j) {
         c = A[i][j]/A[j][j];    /* saves the initial value of A[i][j] after dividing the row with A[j][j] */
         for (k=1; k<=n+1; k++) {
           A[i][k]=A[i][k]-c*A[j][k];    /* subtract initial A[i][j] times other rows i != j */
         }
      }
    }
  //  print(A);
  }
//  print(A);
  printf("\nThe solution is:\n");
  for(i=1; i<=n; i++) {
    x[i]=A[i][n+1]/A[i][i];
    printf("\n x%d=%f\n",i,x[i]);    /* prints roots */
  }
  print(A);

}
