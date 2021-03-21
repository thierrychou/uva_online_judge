#include <stdio.h>

int t, n, m;

int main() {
  scanf("%d", &t);
  for(; t>0; --t) {
    scanf("%d %d", &n, &m);
    printf("%d\n", ((int)(n/3))*((int)(m/3)) );
  }
}

