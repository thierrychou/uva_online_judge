#include <stdio.h>

int t, i, c, d;
double f;

int main() {
  scanf("%d", &t);
  for(i=1; i<=t; ++i) {
    scanf("%d %d", &c, &d);
    f = (9.0 * (double)c) / 5.0 + 32.0 + d;
    printf("Case %d: %.2f\n", i, (f-32.0)*5.0/9.0);
  }
}
