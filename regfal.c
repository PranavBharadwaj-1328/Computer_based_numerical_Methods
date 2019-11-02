#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float a,float b,float c,float x);
/*********Main function begins************/
int main(int argc,char *argv[])
{
  double x0,x1,x,f0,f1,f,p,q,r;
  /* Equation: px^2+qx+r = 0 */
  if (argc != 6) {
    printf ("Syntax: ./regfal p q r x0 x1\n");
    exit(1);
  }
  p = atof(argv[1]);     /* converts first arguments data type to double */
  q = atof(argv[2]);     /* converts second arguments data type to double */
  r = atof(argv[3]);     /* converts third arguments data type to double */
  x0 = atof(argv[4]);    /* converts fourth arguments data type to double */
  x1 = atof(argv[5]);    /* converts fifth arguments data type to double */
  f0 = F(p,q,r,x0);    /* f(x0) */
  f1 = F(p,q,r,x1);    /* f(x1) */
  printf("x_k-1 = %f,x_k = %f,f_k-1 = %f,f_k = %f\n",x0,x1,f0,f1);    /* prints first iteration */
  while (floor (f1*1000) != 0) {    /* While f(x1) is not equal to 0 */
    x = ((x0*f1) - (x1*f0))/(f1 - f0);    /* from secant method */
    f = F(p,q,r,x);    /* f is given the value f(x) */
    if ((f*f1) < 0) {    
      x0 = x;     /* if f*f1 < 0 then the root lies in the range x to x1 */
    }
    else {
      x1 = x;    /* else in between x0 to x */
    }
    f0 = F(p,q,r,x0);    /* f0 is updated */
    f1 = F(p,q,r,x1);    /* f1 is updated */
    printf("x_k-1 = %f,x_k = %f,f_k-1 = %f,f_k = %f\n",x0,x1,f0,f1);    /* prints each iteration */
    if (floor(x0*1000) == floor(x1*1000)) {    /* if x0 = x1 then */
      printf("Root = %f\n",x0);    /* print x0 as the root */


    }
  }
  printf("Root = %f\n",x1);    /* prints the root */
}
/************Main function ends**********/
float F(float a,float b,float c,float x)
{
  return ((a*x*x) + (b*x) + c);    /* returns f(x) */
}

