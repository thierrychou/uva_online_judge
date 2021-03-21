#include<stdio.h>

int deg, i, a, b, c;

int main() {
  while(scanf("%d %d %d %d", &i, &a, &b, &c) != EOF) {
    if(i==0 && a==0 && b==0 && c==0) return 0;
    printf("%d\n", 1080 + ((a>i?40-a+i:i-a) + (b<a?40-a+b:b-a) + (c>b?40-c+b:b-c))*9);
  }
}
