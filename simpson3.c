#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(float x);
/**********Main function begins*********/
int main(int argc,char *argv[])
{
  float a,b,N,h,f[32],x,ans,o = 0,e = 0;    /* a,b are the limits where 2N is the number of intervals and x is the interval,f[] maintains function values at each interval,h is interval length */
  int i = 0,j = 1,k = 2;    /* These are used to maintain count */
  if (argc != 4) {
    printf("Syntax: ./simpson3 a b h\n");    /* prints error message for wrong syntax */
    exit(1);    /* exits from the program */
  }
  a = atof(argv[1]);    /* Takes lower bound */
  b = atof(argv[2]);    /* Takes upper bound */
  h = atof(argv[3]);    /* Takes interval's length as input */
  N = (b - a) / (2 * h);    /* half times number of interval's */
  while (i != (2*N + 1)){
    x = ((i - a) / (2*N));    /* calculates x value at each interval */
    f[i] = fun(x);    /* store f(x) */
    printf("x[%d] = %f, f[%d] = %f\n",i,x,i,f[i]);    /* prints x and f(x) at each interval */
    i++;    /* increments count */
  }
  i = i - 1;    /* here i = 2N */
  ans = ((h*(f[0] + f[i]))/3);    /* adds h/3(f(0) + f(2N)) to the answer */
  while (j != ((2*N) + 1)) {
    o = o + f[j];     /* calculates the sum of function values of the odd intervals */
    j = j + 2;
  }
  while (k != (2*N)) {
    e = e + f[k];    /* calculates the sum of function values of the odd intervals */
    k = k + 2;
  }
  ans = ans + ((h/3) * ((4*o) + (2*e)));    /* adds h/3(4o + 2e) to the answer */
  printf("Ans = %f\n",ans);    /* prints the answer */
}
/************Main function ends************/
float fun(float x)
{
  return(log(1+x));    /* returns f(x) */
}

