#include <algorithm>
#include <cstdio>
#include <cstring>

char str[101];
int g, length, p, l, r;

int main() {
  while(scanf("%d", &g)!=EOF && g!=0) {
      scanf("%s", &str);
      length = strlen(str);
      p = length / g;

      l = 0;
      while(g--) {
          r = l + p;
          std::reverse(str+l, str+r);
	  l = r;
      }
      printf("%s\n", str);
  }
}
