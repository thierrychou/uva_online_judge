#include<stdio.h>

int n, newN, count, i, l, trains[50], temp;

int main() {
  scanf("%d", &n);
  for(; n>0; --n) {
    scanf("%d", &l);
    for(i=0; i<l; ++i) {
      scanf("%d", &trains[i]);
    }

    count = 0;
    do {
      newN = 0;
      for(i=1; i<l; ++i) {
        if(trains[i-1] > trains[i]) {
	  temp = trains[i-1];
	  trains[i-1] = trains[i];
	  trains[i] = temp;
          count++;
       	  newN = i;
        }
      }
      l = newN;
    } while(l!=0);

    printf("Optimal train swapping takes %d swaps.\n", count);
  }
}
