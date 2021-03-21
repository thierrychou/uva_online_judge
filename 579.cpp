#include<stdio.h>
#include<cmath>
#include<algorithm>

int h,m;
double dh, dm, diff;

int main() {
  while(scanf("%d:%d", &h, &m)!=EOF) {
    if(h==0 && m==0) return 0;
    
    dh = (double)h*30.0 + (double)m/2.0;
    dm = (double)m * 6.0;
    diff = fabs(dh-dm);
    printf("%.3f\n", std::min(diff, 360.0-diff));
  }
}
