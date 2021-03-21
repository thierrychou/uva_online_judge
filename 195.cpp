#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int n;
string word;

bool comparator(const char& a, const char& b) {
  char d = tolower(a) - tolower(b);
  return d ? d<0 : a<b;
}

int main() {
  cin>>n;
  for(;n>0;--n) {
    cin >> word;
    sort(word.begin(), word.end(), comparator);
    do {
      cout << word << endl;
    } while(next_permutation(word.begin(), word.end(), comparator));
  }
}
