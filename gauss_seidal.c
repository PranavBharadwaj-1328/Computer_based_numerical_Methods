#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/********Main function begins*********/
int main(int argc,char *argv[])
{
  float A[3][4],x[3],a,b,c;    /* A[3][4] is the equation matrix and x[] and a,b,c maintain the solution obtained at each equation */
  int i = 0,j = 0;    /* To maintain count */
  /* prints error for wrong syntax */
  if (argc != 4) {
    printf("Syntax : ./gauss_seidel x[0] x[1] x[2] (where x[] are the initial guesses of roots)\n");
    exit(1);
  }
  /* Takes input from user */
  for (i = 0;i < 3;i++) {
    for(j = 0;j < 4;j++) {
      printf("A[%d][%d] = ",i,j);
      scanf("%f",&A[i][j]);
    }
  }
  x[0] = atof(argv[1]);    /* x[0] */
  x[1] = atof(argv[2]);    /* x[1] */
  x[2] = atof(argv[3]);    /* x[2] */
  j = 0;
  a = x[0];
  b = x[1];
  c = x[2];
  while (j != 32) {
    x[0] = (A[0][3] - (A[0][1] * x[1]) - (A[0][2] * x[2])) / A[0][0];    /* x[0] = (b0 - A[0][1]x[1] - A[0][2]x[2]) / A[0][0] */
    x[1] = (A[1][3] - (A[1][0] * x[0]) - (A[1][2] * x[2])) / A[1][1];    /* x[1] = (b1 - A[1][0]x[0] - A[1][2]x[2]) / A[1][1] */ 
    x[2] = (A[2][3] - (A[2][0] * x[0]) - (A[2][1] * x[1])) / A[2][2];    /* x[2] = (b2 - A[2][1]x[1] - A[2][0]x[0]) / A[2][2] */
    /* Checks whether the root converges before maximum iterations (i.e. 32) */
    if (a == x[0] && b == x[1] && c == x[2]) {
      printf("Solution :\n");
      for (i = 0;i < 3;i++) {
        printf("x[%d] = %f\n",i,x[i]);
      }
      exit(1);
    }
    /* prints each iteration */
    printf("Iteration %d \n",j+1);
    for (i = 0;i < 3;i++) {
      printf("x[%d] = %f\n",i,x[i]);
    }
      printf("\n");
   /* updates a b and c values so that they can be used to check the convergence of the root */
    a = x[0];
    b = x[1];
    c = x[2];
    j++;
  } 
  /* prints the solution obtained after 32 iterations incase of no convergence */     
  printf("Solution :\n");
  for (i = 0;i < 3;i++) {
    printf("x[%d] = %f\n",i,x[i]);
  }
  exit(0);
}
/****************Main Function Ends*******************/ 
