#include <stdio.h>

int c, t, n;
int current, height, hj, lj;

int main() {
  scanf("%d", &t);
  for(c=1; c<=t; ++c) {
    hj = 0;
    lj = 0;
    scanf("%d", &n);
    for(int x=0; x<n; ++x) {
      scanf("%d", &height);

      if(x==0) {
	current = height;
	continue;
      }
 
      if(current < height) {
        ++hj;
      } else if(current > height) {
        ++lj;
      }
      current = height;
    }

    printf("Case %d: %d %d\n", c, hj, lj);
  }
}
