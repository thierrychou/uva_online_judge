#include<stdio.h>
#include<string.h>

char line[33];
unsigned int c, sum, t;
int length;

int main() {
  while(scanf("%s", line) != EOF) {
    length = strlen(line);
    if(length==1 && line[0]=='0') return 0;

    c=1;
    sum = 0;
    for(length-=1; length>=0; --length) {
      c<<=1;
      t = line[length] - '0';
      if(t!=0) {
        sum += t * (c-1);
      }
    }
    printf("%d\n", sum);
  }
}
