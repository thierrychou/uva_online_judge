#include <stdio.h>
#include <math.h>

#define EPS 1e-8

double x, x1;
int p,q,r,s,t,u;

double f(double x) {
  return (double)p*exp(-x) + (double)q*sin(x) + (double)r*cos(x) +
	  (double)s*tan(x) + (double)t*x*x + (double)u;
}

double fd(double x){ // the derivative of function f
  return (double)-p*exp(-x) + (double)q*cos(x) - (double)r*sin(x) +
	 (double)s/(cos(x)*cos(x)) + 2.0*(double)t*x;
}
 
double newton(){
  if (f(0)==0) return 0;
  for (double x=0.5; ;){             // initial guess x = 0.5
    double x1 = x - f(x)/fd(x);      // x1 = next guess
    if (fabs(x1-x) < EPS) return x;  // the guess is accurate enough
    x = x1;
  }
}

int main() {
  while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)!=EOF) {
    if(f(0)*f(1) > 0) {
      printf("No solution\n");
    } else {
      printf("%.4lf\n", newton());
    }
  }
}
