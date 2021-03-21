#include<stdio.h>

bool ordered;
int n, j;
int lumberjacks[10];

int main() {
  scanf("%d", &n);
  printf("Lumberjacks:\n");
  for(; n>0; --n){
    for(j=0; j<10; ++j){
      scanf("%d", &lumberjacks[j]); 
    }

    ordered = true;
    if(lumberjacks[0] < lumberjacks[1]){
      for(j=2; j<10; ++j){
        if(lumberjacks[j-1]>lumberjacks[j]) {
          ordered = false;
          break;
        }
      }
    }else{
      for(j=2; j<10; ++j){
        if(lumberjacks[j-1]<lumberjacks[j]) {
          ordered = false;
          break;
        }
      }
    }

    if(ordered){
      printf("Ordered\n");
    }else{
      printf("Unordered\n");
    }
  }
} 
