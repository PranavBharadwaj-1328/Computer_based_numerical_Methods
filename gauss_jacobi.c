#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/********Main function begins*********/
int main(int argc,char *argv[])
{
  float A[3][4],x1[3],x[3];    /* A[3][4] is the equation matrix and x and x1 maintain the solution obtained at each equation */
  int i = 0,j = 0;    /* To maintain count */
  /* Takes input from user */
  for (i = 0;i < 3;i++) {
    for(j = 0;j < 4;j++) {
      printf("A[%d][%d] = ",i,j);
      scanf("%f",&A[i][j]);
    }
  }
  /* initiates the solution matrices to 0 */
  for(i = 0;i < 3;i++) {
    x[i] = 0;
    x1[i] = 0;
  }
  j = 0;
  while (j != 32) {
    x[0] = (A[0][3] - (A[0][1] * x1[1]) - (A[0][2] * x1[2])) / A[0][0];    /* x[0] = (b0 - A[0][1]x1[1] - A[0][2]x1[2]) / A[0][0]  (here x1[] contains the values obtained in previous iteration) */   
    x[1] = (A[1][3] - (A[1][0] * x1[0]) - (A[1][2] * x1[2])) / A[1][1];    /* x[1] = (b1 - A[1][0]x1[0] - A[1][2]x1[2]) / A[1][1]  (here x1[] contains the values obtained in previous iteration) */
    x[2] = (A[2][3] - (A[2][0] * x1[0]) - (A[2][1] * x1[1])) / A[2][2];    /* x[2] = (b2 - A[2][1]x1[1] - A[2][0]x1[0]) / A[2][2]  (here x1[] contains the values obtained in previous iteration) */
    /* Checks whether the root converges before maximum iterations (i.e. 32) */
    if (x1[0] == x[0] && x1[1] == x[1] && x1[2] == x[2]) {    
      printf("Solution :\n");
      for (i = 0;i < 3;i++) {
        printf("x[%d] = %f\n",i,x[i]);
      }
      exit(1);
    }
    /*prints each iteration */
    printf("Iteration %d \n",j+1);
    for (i = 0;i < 3;i++) {
      printf("x[%d] = %f\n",i,x[i]);
    }
    printf("\n");
    /* stores newly obtained x values in x1 */
    x1[0] = x[0];
    x1[1] = x[1];
    x1[2] = x[2];
    j++;    /* increments count */
  }
  /* prints solution obtained after 32 iterations */
  printf("Solution :\n");
  for (i = 0;i < 3;i++) {
    printf("x[%d] = %f\n",i,x[i]);
  }
  exit(0);
}
/*****************Main Function Ends**********************/
