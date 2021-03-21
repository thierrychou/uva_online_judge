#include<ctype.h>
#include<stdio.h>
#include<string.h>

int i, j;
int sum[2];
char name[2][26];
float r;

inline int oneDigit(int x) {
  int total=0;
  while(x>0){
    total += x%10;
    x/=10;
  }
  return total;
}

int main() {
  while(gets(name[0]) && gets(name[1])) {
    for( i=0; i<2; ++i) {
      sum[i] = 0;
      for( j=strlen(name[i])-1; j>=0; --j) {
        if(isalpha(name[i][j])) {
          sum[i] += tolower(name[i][j]) - 'a' + 1;
        }
      }
      while(sum[i]>=10) {
        sum[i] = oneDigit(sum[i]);
      }
    }
    r = (sum[0]<sum[1]) ? (float)sum[0]/(float)sum[1] : (float)sum[1]/(float)sum[0];
    printf("%.02f %%\n", r*100.0);
  }
}
