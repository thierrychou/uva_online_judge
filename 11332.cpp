#include <stdio.h>

unsigned long long n, t;

int main(){
  while(scanf("%llu", &n)!=EOF){
    if(n==0){
      return 0;
    }

    t = n%9;
    if(t==0){
      t=9;
    }
    printf("%llu\n", t);
  }
}
