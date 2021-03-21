#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int g;
char line[20];

int main() {
  int h=11;
  int l=0;
  while(gets(line) != NULL) {
    g = atoi(line);
    if(g==0) {
      return 0;
    }

    gets(line);
    if(strcmp(line, "too high")==0) {
      h = min(g, h);
    } else if(strcmp(line, "too low")==0) {
      l = max(g, l);
    } else {
      if(l<g && g<h) {
        printf("Stan may be honest\n");
      } else {
        printf("Stan is dishonest\n");
      }
      h = 11;
      l = 0;
    }
  }
}
