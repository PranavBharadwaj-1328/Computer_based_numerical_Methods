#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float a,float b,float c,float x);
int main(int argc,char *argv[])
{
  float x0,x1,x,f0,f1,p,q,r;
  int count = 1;
  if (argc != 6) {
    printf("Syntax: ./secant p q r x0 x1 (Where p,q,r are coefficients of the qudratic equation and x0 is the first guess and x1  is the second guess)\n");
    exit(1);
  }
  /* Equation: px^2+qx+r = 0 */
  p = atof(argv[1]);    /* converts first argument's datatype into double */
  q = atof(argv[2]);    /* converts second argument's datatype into double */
  r = atof(argv[3]);    /* converts third argument's datatype into double */
  x0 = atof(argv[4]);   /* converts fourth argument's datatype into double */
  x1 = atof(argv[5]);   /* converts fifth argument's datatype into double */
  f0 = F(p,q,r,x0);     /* f(x0) */
  f1 = F(p,q,r,x1);     /* f(x1) */
  printf("%d. x_k-1 = %f,x_k = %f,f_k-1 = %f,f_k = %f\n",count,x0,x1,f0,f1); /* prints first iteration */
  count++;
  while (floor(f1*1000000) != 0) {   /* While f(x1) is not equal to 0 */
    x = ((x0*f1) - (x1*f0))/(f1 - f0);/* x_k+2 = ((x_k*f(x_k+1)) - (x_k+1*f(x_k))) / (f(x_k+1) - f(x_k)) */
    x0 = x1;    /* x_k is updated to x_k+1 */ 
    x1 = x;     /* x_k+1 is updated to x_k+2 */    
    f0 = F(p,q,r,x0);    /* f(x_k) for the new x_k */
    f1 = F(p,q,r,x1);    /* f(x_k+1) for the new x_k+1 */
    printf("%d. x_k-1 = %f,x_k = %f,f_k-1 = %f,f_k = %f\n",count,x0,x1,f0,f1);    /* prints each iteration */
    count++;
  }
  printf("Root = %f\n",x1);    /* prints the root */
}
float F(float a,float b,float c,float x)
{
  return ((a*x*x) + (b*x) + c);    /* this function returns f(x) */
}

