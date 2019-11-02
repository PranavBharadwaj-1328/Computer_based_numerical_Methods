#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float a,float b,float c,float x);
float F1(float a,float b,float c,float x); 
int main(int argc,char *argv[])
{
  int i = 0;    /* To maintain the count of the no. of iterations */ 
  double a,b,c,x0,x1,f,f1,f2;    /* a,b,c are the coefficients of the quadratic equation,
                                 x0 is the root and f = f(x),f'(x) = f1,f"(x) = f2 */ 
  if (argc != 5) {
    printf("Syntax : ./chebysher a b c x0 (where a,b,c are the coefficients of quaratic equation and x0 is the first guess)\n");
    exit(1);
  }   
  a = atof(argv[1]);    /* converts first argument's datatype into double */
  b = atof(argv[2]);    /* converts second argument's datatype into double */
  c = atof(argv[3]);    /* converts third argument's datatype into double */
  x0 = atof(argv[4]);   /* converts fourth argument's datatype into double */
  f = F(a,b,c,x0);   /* f(x0) */
  f1 =F1(a,b,c,x0);    /* f'(x0) */
  f2 = (2*a);    /*f"(x0) */
  printf("Iteration %d x_%d = %f\n",i,i,x0);    /* prints first iteration */
  i++;    /* increments the count */
  while (floorf(f*10000) != 0) {    /* while f(x0) rounded of to 4 decimal place not equal to 0 */
    x1 = x0 - (f/f1) - (0.5*((f*f)/(f1*f1*f1))*f2);    /* x_k+1 = x_k - (f(x0)/f'(x0)) - 1/2(f(x0)^2 / f'(x0)^3) (f"(x0)) */
    if (x1 == x0) {
      printf("Root = %f\n",x0);
      exit(0);
    }
    x0 = x1;    /* x0 (i.e. x_k) is updated to x1 (i.e. x_k+1) */
    f = F(a,b,c,x0);    /* f(x_k) is updated to f(x_k+1) */
    f1 = F1(a,b,c,x0);     /* f'(x_k) is updated to f'(x_k+1) */
    f2 = (2*a);     /* f"(x_k) is updated to f"(x_k+1) */
    printf("Iteration %d x_%d = %f\n",i,i,x0);    /* prints each iteration */
    i++;    /* maintains count of the iterations */
  }
  printf("Root = %f\n",x0);    /* prints the root */
}

float F(float a,float b,float c,float x) 
{
  return ((a*x*x) + (b*x) + c);    /* this function returns f(x) */
}
float F1(float a,float b,float c,float x) 
{
  return ((2*a*x) + b);    /* this function returns f'(x) */
} 
