#include<cstdio>

int index, mid, length;
unsigned long int x, result, list[10001];

int main() {
  length = 0;
  while(scanf("%lu", &x)!=EOF) {
    //insertion
    index = length++;
    while(index>0 && x<list[index-1]) {
      list[index] = list[index-1];
      --index;
    }
    list[index] = x;

    //calc mediam
    mid = length/2;
    if(length%2==0) {
      result = (list[mid] + list[mid-1]) / 2;
    } else {
      result = list[mid];
    }

    //print
    printf("%lu\n", result);
  }
}
