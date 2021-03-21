#include<stdio.h>

int i, n, stacks[50], sum, avg, moves, test=1;

int main() {
  while(scanf("%d", &n)!=EOF) {
    if(n==0) return 0;

    sum = 0;
    moves = 0;
    for(i=0; i<n; ++i) {
      scanf("%d", &stacks[i]);
      sum += stacks[i];
    }
    avg = sum/n;
    for(i=0; i<n; ++i) {
      if(stacks[i] > avg) {
        moves += stacks[i] - avg;
      }
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n\n", test++, moves);
  }
}
