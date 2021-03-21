#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool palindrome;
int s, r, length;
char line[50000];

int main() {
  while(gets(line)!=NULL) {
    if(strcmp(line, "DONE")==0) {
      return 0;    
    }
    palindrome = true;
    length = strlen(line);
    s = 0;
    r = length-1;
    while(s<r) {
      while(s<length && !isalpha(line[s])) ++s;
      while(r>0      && !isalpha(line[r])) --r;
      if(tolower(line[s])!=tolower(line[r])) {
        palindrome = false;
      }
      s++;
      r--;
    } 
    if(palindrome) {
      printf("You won't be eaten!\n");
    } else {
      printf("Uh oh..\n");
    }
  }
}
