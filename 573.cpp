#include<stdio.h>
#include<algorithm>

int h,u,d,f,day,height;

int main() {
  while(scanf("%d %d %d %d", &h, &u, &d, &f)!=EOF && h!=0) {
    h *= 100;
    f  = u*f;
    u *= 100;
    d *= 100;

    day = 0;
    height = 0;
    while(0<= height && height<=h) {
      ++day;
      height += u; //after climbing
      if(height<=h) height -= d; //sliding

      u = std::max(u-f, 0);
    }
    if(height>h) {
      printf("success on day %d\n", day);
    } else {
      printf("failure on day %d\n", day);
    }
  }
}
