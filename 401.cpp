#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int i, start, end;
bool isPalindrome, isMirror;
char word[21];
const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char* reverses   = "A!!!3!!HIL!JM!O!!!2TUVWXY51SE!Z!!8!";

int main() {
  map<char, char> reverse;
  for(i=0; i<35; ++i) {
    reverse[characters[i]] = reverses[i];
  }

  while(gets(word)!=NULL) {
    isPalindrome = true;
    isMirror = true;
    start = 0;
    end = strlen(word) -1;
    while(start<=end) {
      if(word[start] != word[end]) {
        isPalindrome = false;
      }
      if(word[start] != reverse[word[end]]) {
        isMirror = false;
      }
      if(!isPalindrome && !isMirror) break;
      ++start;
      --end;
    }

    printf("%s", word);

    if(isPalindrome) {
      if(isMirror) {
        printf(" -- is a mirrored palindrome.\n\n");
      } else {
        printf(" -- is a regular palindrome.\n\n");
      }
    } else {
      if(isMirror) {
        printf(" -- is a mirrored string.\n\n");
      } else {
        printf(" -- is not a palindrome.\n\n");
      }
    }
  }
}

