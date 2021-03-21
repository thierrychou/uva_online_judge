#include<stdio.h>
#include<algorithm>

int t,n,c,cMax;

int main(){
  scanf("%d", &t);
  for(int x=1; x<=t; ++x) {
    cMax = 0;
    scanf("%d", &n);

    for(; n>0; --n) {
      scanf("%d", &c);
      cMax = std::max(cMax, c);
    }
    printf("Case %d: %d\n", x, cMax);
  }
}
