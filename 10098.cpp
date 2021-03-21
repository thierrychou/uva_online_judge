#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
string word;

int main() {
  cin>>n;
  for(;n>0;--n) {
    cin >> word;
    sort(word.begin(), word.end());
    do {
      printf("%s\n", word.c_str());
    } while(next_permutation(word.begin(), word.end()));
    printf("\n");
  }
}
