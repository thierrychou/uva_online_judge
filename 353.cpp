#include<stdio.h>
#include<iostream>
#include<set>
#include<string>

using namespace std;

int pos, len, length;

bool isPalindrome(const char* str, int length) {
  int start = 0;
  int end = length-1;
  while(start<end) {
    if(str[start] != str[end]) {
      return false;
    }
    ++start;
    --end;
  }
  return true;
}

int main() {
  string word;
  set<string> count;

  while(cin>>word) {
    count.clear();
    length = word.size();
    for(len=1; len<=length; ++len) {
      for(pos=0; pos<length-len+1; ++pos) {
        string str = word.substr(pos, len);
        //printf("pos=%d, len=%d, %s\n", pos, len, str.c_str());
        if(isPalindrome(str.c_str(),len)) {
          count.insert(str);
        }
      }
    }
    printf("The string '%s' contains %d palindromes.\n", word.c_str(), count.size());
  }
}

