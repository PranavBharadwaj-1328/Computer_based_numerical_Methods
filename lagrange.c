#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float l(float xi,float x[32],int j,int n);    /* function returns l_i(x) */
/*************Main function begins*************/
int main(int argc,char *argv[])
{
//  system("gcc -Wall lagrange.c -o lagrange -lm");
//  system("./lagrange");
  float x[32],xi = 0,f[32],p = 0;    /* x[32] ,f[32 is the array of x and f(x) respectively */
  int n,i = 0,j = 0;    /* i and j are used to maintain count */
  if (argc != 2) {
    printf("Syntax:./lagrange n(n is the no. of values of x)\n");
    exit(1);
  } 
  n = atoi(argv[1]);    /* n is the no. of values of x */
  printf("Enter x value:");  
  scanf("%f",&xi);    /* xi is the value for which root is to be found */
  /**** The below loop takes x value and f(x) ***/
  while (i != n) {
    printf("Enter x_%d =",i);
    scanf("%f",&x[i]);
    printf("Enter f(x_%d) =",i);
    scanf("%f",&f[i]);
    i++;
  }
  /*** p is the value of the function at xi ***/
  while (j != n) {
    p = p + (l(xi,x,j,n)*f[j]);    /* p is initialized to 0 when j = i p = p_i + li(xi)f(xi) p_i is the previously obtained p */ 
    j++;    /* increments count */
  }
  printf("f(%f) = %f\n",xi,p);    /* prints the function value at xi */    
}
/*************Main function ends*******************/
float l(float xi,float x[32],int j,int n) {
  float a = 1,b = 1;
  int i = 0;
  while (i != n) {
    if (i == j) {
      i = i + 1;
      if (i == n) {
        printf("l[%d] = %f\n",j,a / b); 
        return (a/b);
      }
    }
    a = (a*(xi - x[i]));    /* a  will be equal to product of (x - xj) where j != k at l_k */
    b = (b*(x[j] - x[i]));  /* b  will be equal to product of (xk - xj) where j != k at l_k */
    i++;    /* increments count */
  }
  printf("l[%d] = %f\n",j,a / b);    /* prints l value */
  return (a / b);    /* returns l value */
}
