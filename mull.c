#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float p,float q,float r,float x);
/**********Main function begins************/
int main(int argc,char *argv[])
{
  float xa,xb,xc,fa,fb,fc,x,l,l1,g,c,d,y,z,p,q,r;
  if (argc != 7) {   /* returns errors when wrong input */
    printf("Syntax: ./mull p q r xa xb xc(p,q,r are coefficients and xa,xb,xc are the guesses)\n");
    exit(1);
  }
  p = atof(argv[1]);    /* takes p as first argument */
  q = atof(argv[2]);    /* takes q as second argument */
  r = atof(argv[3]);    /* takes r as third argument */
  xa = atof(argv[4]);   /* takes x_-1 as fourth argument */
  xb = atof(argv[5]);   /* takes x_0 as fifth argument */
  xc = atof(argv[6]);   /* takes x_1 as sixth argument */
  fa = F(p,q,r,xa);    /* f(x_-1) */
  fb = F(p,q,r,xb);    /* f(x_0) */
  fc = F(p,q,r,xc);    /* f(x_1) */
  l = (xc - xb)/(xb - xa);    /* l_0 (lambda) */
  d = l + 1;    /* delta */
  g = (l*l*fa) - (d*d*fb) + ((l + d) * fc);
  c = (l * ((l*fa) - (d*fb) + fc));
  printf("%f,%f,%f\n",xa,xb,xc);
  while (floor(fc*1000000) != 0) {    /* while f(x_1) is not = 0 */
    y = (-2*d*fc) / (g + sqrt((g*g) - (4*c*d*fc)));    
    z = (-2*d*fc) / (g - sqrt((g*g) - (4*c*d*fc)));
    if ((y*y) < (z*z)) {    /* comparing absolute values */
      l1 = y;    /* lambda1 = y */
    }
    else {
      l1 = z;    /* lambda1 = z */ 
    }
    x = xc + (l1*(xc - xb));    /* root obtained */
    xa = xb;
    xb = xc;
    xc = x;
    fa = F(p,q,r,xa);
    fb = F(p,q,r,xb);
    fc = F(p,q,r,xc);
    d = l1 + 1;
    g = (l1*l1*fa) - (d*d*fb) + ((l1 + d) * fc);
    c = (l1 * ((l1*fa) - (d*fb) + fc));
    if (floor(xb*10000) == floor(xc*10000)) {
      printf("Root = %f\n",xc);
      exit(0);
    }
    printf("%f,%f,%f\n",xa,xb,xc);
  }
  printf("Root = %f\n",xc);
}
/************Main function ends***********/
float F(float p,float q,float r,float x)
{
  return ((p*x*x) + (q*x) + r);     /* returns f(x) */
}
