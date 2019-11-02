#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(float x);
/**********Main function begins*********/
int main(int argc,char *argv[])
{
  float a,b,N,h,f[64],x,ans,n = 0;    /* a,b are the limits where N is the number of intervals and x is the interval,f[] maintains function values at each interval,h is interval length */
  int i = 0,j = 1;    /* These are used to maintain count */
  if (argc != 4) {
    printf("Syntax: ./trapezoid2 a b h\n");    /* prints error message for wrong syntax */
    exit(1);    /* exits from the program */
  }
  a = atof(argv[1]);    /* Takes lower bound */
  b = atof(argv[2]);    /* Takes upper bound */
  h = atof(argv[3]);    /* interval length */
  N = (b - a) / (h);    /* number of intervals */
  while (i != (N + 1)){
    x = a + (i*h);    /* calculates x value at each interval */
    f[i] = fun(x);    /* store f(x) */
    printf ("x[%d] = %f, f[%d] = %f\n",i,x,i,f[i]);    /* prints x and f(x) at each interval */
    i++;    /* increments count */
  }
  i = i - 1;    /* here i = N */
  ans = ((h*(f[0] + f[i]))/2);    /* adds h/2(f(0) + f(N)) to the answer */
  while (j < i) {
    n = n + f[j];
    j++;
  }
  ans = ans + (n*h);    /* adds h(f(x_1) + ......+f(x_N-1)) to the answer */
  printf("Ans = %f\n",ans);    /* prints the answer */
}
/************Main function ends************/
float fun(float x)
{
  return(0.2 + (25*x) + (3*x*x));    /* returns f(x) */
}

