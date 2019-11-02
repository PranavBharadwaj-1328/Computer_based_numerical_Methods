#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float a,float b,float c,float x);
float F1(float a,float b,float c,float x);
int main(int argc,char *argv[])
{
  float x0,x1,x2,x,a,b,c;
  if (argc != 5) {
    printf ("Syntax: ./newton a b c x0 (a,b,c are coefficients and x0 is first guess\n");
    exit(1);
  }
  a = atof(argv[1]);     /* converts the data type of a to double */
  b = atof(argv[2]);     /* converts the data type of b to double */
  c = atof(argv[3]);     /* converts the data type of c to double */
  x0 = atof(argv[4]);    /* converts the data type of x0 to double */
  int i = 1;    /* maintains count */
  x1 = F(a,b,c,x0);     /* f(x0) */
  x2 = F1(a,b,c,x0);    /* f'(x0) */
  printf("iteration %d = %f\n",i,x0);    /* prints first iteration */
  while (floorf(x1*100000) != 0) {    /* while f(x) is not equal to 0 */
    i++;    /* increments iteration count */    
    x = x0 - (x1/x2);    /* x_k+1 = x_k - (f(x_k) / f'(x_k)) */
    x0 = x;    /* x_k is updated to x_k+1 */
    x1 = F(a,b,c,x0);    /* f(x_K) after change */
    x2 = F1(a,b,c,x0);   /* f'(x_k) after change */
    printf("iteration %d = %f\n",i,x0);    /* prints each iteration */
  }
  printf("Root = %f\n",x0);    /* prints the root */
}

float F(float a,float b,float c,float x)
{
  return ((a*x*x) + (b*x) + c);
}
float F1(float a,float b,float c,float x)
{
  return ((a*x*2) + b);
}
 
