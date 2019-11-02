/* This program is used to evaluate a root of a quadratic equation
* f(x)= Px^2+Qx+r
* Using bisection method
* When given coefficients P,Q,r and the values a,b such that f(a)*f(b) < 0
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
  /*Equation px^2+qx+r = 0 */
  /* Root of a quadratic equation using bisection method */
  if (argc != 6) {    /*returns error when arguments are not properly entered */
     printf("Syntax : ./bisection p q r a b \n");
     /* Here p,q,r are the coefficients of the quadratic equation; a,b are
     the range of values in which the root lies */
     exit(1);
  }
  /********* Bisection Method *************/
  double f0,f1,a,b,c,p,q,r;
  p = atof(argv[1]);   /* converts first argument's data type to double */
  q = atof(argv[2]);   /* converts second argument's data type to double */ 
  r = atof(argv[3]);   /* converts third argument's data type to double */
  a = atof(argv[4]);   /* converts fourth argument's data type to double */
  b = atof(argv[5]);   /* converts fifth argument's data type to double */
  f0 = (p*a*a) + (q*a) + r;/* value of f(a) is stored in f0*/
  f1 = (p*b*b) + (q*b) + r;/* value of f(b) is stored in f1 */
  if (f0*f1 > 0) {    /* if f(a)*f(b) > 0 then root doesnt lie in the specified range */  
    printf("Root not in specified range\n");    /* prints error message */
    exit(1);    /* exits from the program */
  }
  printf("a = %f,b = %f,f(a) = %f,f(b) = %f\n",a,b,f0,f1);
  if (floor(f0*10000) == 0) {
    printf("Root = %f\n",a);
    exit(0);
  }
  if (floor(f1*10000) == 0) {
    printf("Root = %f\n",b);
    exit(0);
  }
  while ((floor(f0*10000)*floor(f1*10000)) != 0) {    /* rounds of the value of f0 and f1 upto 6 decimals */ 
    c = (a+b)/2;    /* c is the median in between a and b */ 
    if ((((p*c*c) + (q*c) + r)*f1) < 0) {    /* If f(c)*f(b) < 0 then the root lies in between c and b */
      a = c;    /* a value is updated to c */
    }
    if ((((p*c*c) + (q*c) + r)*f1) > 0) {    /* If f(c)*f(b) > 0 then the root lies in between a and c */
      b = c;    /* b value is updated to c */
    }
    if ((p*c*c) + (q*c) + r == 0) {    /* if f(c) = 0 then c is the root of the equation */  
      printf("%f is the root\n",c);    /* prints the root */
      exit(0);
    }
    f0 = (p*a*a) + (q*a) + r;        /* updates the function value f0 to f(a) */
    f1 = (p*b*b) + (q*b) + r;        /* updates the function value f1 to f(b) */
    printf("a= %f,b = %f,f(a) = %f,f(b) = %f\n",a,b,f0,f1);    /* prints the iterations and the value of the functions at those iterations */
  }
  printf("Root = %f\n",c);    /* Prints the root */
}

/*********Output********/
/*
 Syntax : ./bisection p q r a b
 when the quadratic equation is px^2+qx+r=0 and a,b are the guesses in which the root lies
*/
/*
 When input equation = x^2+5x+2 (i.e. p = 1,q = 5,r = 2) and the values of a and b are 0 and -0.47 respectively (i.e. a = 0 and b = -0.47) then  output is :
a = 0.000000,b = -0.470000,f(a) = 2.000000,f(b) = -0.129100
a= -0.235000,b = -0.470000,f(a) = 0.880225,f(b) = -0.129100 
a= -0.352500,b = -0.470000,f(a) = 0.361756,f(b) = -0.129100
a= -0.411250,b = -0.470000,f(a) = 0.112877,f(b) = -0.129100
a= -0.411250,b = -0.440625,f(a) = 0.112877,f(b) = -0.008975
a= -0.425937,b = -0.440625,f(a) = 0.051735,f(b) = -0.008975
a= -0.433281,b = -0.440625,f(a) = 0.021326,f(b) = -0.008975
a= -0.436953,b = -0.440625,f(a) = 0.006162,f(b) = -0.008975
a= -0.436953,b = -0.438789,f(a) = 0.006162,f(b) = -0.001409
a= -0.437871,b = -0.438789,f(a) = 0.002376,f(b) = -0.001409
a= -0.438330,b = -0.438789,f(a) = 0.000483,f(b) = -0.001409
a= -0.438445,b = -0.438560,f(a) = 0.000010,f(b) = -0.000463
a= -0.438445,b = -0.438502,f(a) = 0.000010,f(b) = -0.000227
a= -0.438445,b = -0.438452,f(a) = 0.000010,f(b) = -0.000020
a= -0.438445,b = -0.438448,f(a) = 0.000010,f(b) = -0.000005
a= -0.438447,b = -0.438448,f(a) = 0.000002,f(b) = -0.000005
a= -0.438447,b = -0.438448,f(a) = 0.000002,f(b) = -0.000001
a= -0.438447,b = -0.438448,f(a) = 0.000001,f(b) = -0.000001
Root = -0.438447
*/
/*
K.Pranav Bharadwaj
Roll no. 17MCME06
*/   
