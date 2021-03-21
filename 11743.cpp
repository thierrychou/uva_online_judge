#include <stdio.h>

int n, i, j, sum;
char num[4][5];

int addDigits(int x){
  int total = 0;
  while(x>0) {
    total += x%10;
    x /= 10;
  }
  return total;
}

int main() {
  scanf("%d", &n);
  for(; n>0; --n) {
    for(i=0; i<4; ++i) {
      scanf("%s", num[i]);
    }

    sum = 0;
    for(i=0; i<4; ++i) {
      for(j=0; j<4; ++j) {
        if(j%2==0) {
          sum += addDigits((num[i][j]-'0') * 2);
	} else {
	  sum += num[i][j]-'0';
	}
      }
    }
    if(sum%10 == 0){
      printf("Valid\n");
    }else{
      printf("Invalid\n");
    }
  }
}
