#include<stdio.h>
#include<string.h>
#include<algorithm>

char line[51];

int main() {
  while(scanf("%s", line)!=EOF) {
    if(line[0]=='#') {
      return 0;
    }
    if(std::next_permutation(line, line+strlen(line))) {
      printf("%s\n", line);
    } else {
      printf("No Successor\n");
    }
  }
}
