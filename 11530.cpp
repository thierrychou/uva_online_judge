#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, j, t, count, length;

char line[101];
char press[] = "12312312312312312341231234";

int main() {
  t = atoi(gets(line));
  for(i=1; i<=t; ++i) {
    gets(line);
    count = 0;
    length = strlen(line);
    for(j=0; j<length; ++j) {
      if(line[j] == ' '){
        ++count;
      } else {
        count += press[line[j] -'a'] - '0';
      }
    }
    printf("Case #%d: %d\n", i, count);
  }
}
