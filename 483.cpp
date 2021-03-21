#include<stdio.h>
#include<cstring>

char line[50000], t, *ws, *we;

void reverse(int start, int end) {
  while(start<end) {
    t = line[start];
    line[start] = line[end];
    line[end] = t;

    ++start;
    --end;
  }
}

int main() {
  while(gets(line)!=NULL) {
    ws = line;
    while((we=strchr(ws, ' ')) != NULL) {
      reverse(ws-line, we-line-1);
      ws = we + 1;
    }
    reverse(ws-line, strlen(line)-1);
    printf("%s\n", line);
  }
}
