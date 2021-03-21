#include <stdio.h>
#include <string.h>

int length, i;
char c, line[31];
const char* map = "22233344455566677778889999";

int main() {
  while(gets(line)!=NULL) {
    length = strlen(line);
    for(i=0; i<length; ++i) {
      c = line[i];
      if(c!='1'&&c!='0'&&c!='-') {
	line[i] = map[c - 'A'];
      }
    }
    printf("%s\n", line);
  }
}
