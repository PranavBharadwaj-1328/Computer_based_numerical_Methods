#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
  int n,i = 0,j = 0,k = 0,l = 0,p = 0,m,o;
  float h,c0,c1,h1; 
  n = atoi(argv[1]);
  h = atof(argv[2]);
  float a[n],b[n - 1],x[n];
  while (l != n+1) {
    printf("a_%d =",l);
    scanf("%f",&a[l]);
    l++;
  }
  for (o = 0;o < n;o++) {
    x[o] = a[o];
  }
  b[0] = a[0];
  while (p != 2) {
    while (i <= n) {
      b[i + 1] = x[i+1] + (b[i] * h);
      printf("b[%d] = %f\n",i+1,b[i + 1]);
      i++;
    }  
    c0 = b[n];
    printf("c0 = %f\n",c0);
    while (j != n) {
      a[j+1] = b[j+1];
      j++;
    }
    while (k != n) {
      b[k + 1] = a[k+1] + (b[k] * h);
      printf("b[%d] = %f\n",k+1,b[k + 1]);
      k++;
    }
    c1 = b[n - 1];
    printf("c1 = %f\n",c1);
    h1 = h - (c0/c1);
    printf("h = %f\n",h1);
    h = h1;
    i = 0;
    j = 0;
    k = 0;
    p++;
  }
    printf("Root = %f\n",h1);
}
