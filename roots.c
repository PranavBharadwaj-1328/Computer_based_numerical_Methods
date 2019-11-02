#include <stdio.h>
#include <math.h>

int main()
{
  float a,b,c,x,x0,x1,x2;
  printf("Equation: ax^2 + bx + c = 0\n");    /* Quadratic Equation ax^2 + bx + c = 0 */
  printf("a =");
  scanf("%f",&a);    /* coefficient a */
  printf("b =");
  scanf("%f",&b);    /* coefficient b */
  printf("c =");
  scanf("%f",&c);     /* coefficient c */
  printf("Enter first guess =");   
  scanf("%f",&x0);     /* x0 (i.e. first guess) */
  x = x0;              /* x contains the first guess */
  x1 = -c / ((a*x0) + b);
  while (x0 != x1) {
    x0 = x1;                  /* x_k is changed to x_k+1 */
    x1 = -c / ((a*x0) + b);   /* since x_k is changed x_k+1 is also changed untill x_k = x_k+1 */
  }
  printf("root1 = %f\n",x1); /* prints the first root */
  x2 = (-c / (a*x)) -(b/a) ;
  while (x != x2) {
    x = x2;                  /* x_k is changed to x_k+1 */
    x2 = (-c / (a*x)) -(b/a) ;    /* since x_k is changed x_k+1 is also changed untill x_k = x_k+1 */
  }
  printf("root2 = %f\n",x2);    /* prints the second root */
    
}
/*
K Pranav Bharadwaj
Roll no:17MCME06
IM.tech 3rd sem
*/

