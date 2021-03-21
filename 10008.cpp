#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

int n, i, length;
char line[256], up;

std::map<char, int> count;
std::vector<std::pair<char,int> > output;

struct greaterComparator {
  bool operator() (const std::pair<char, int>& x, const std::pair<char, int>& y) const {
    return x.second > y.second;
  }
}; 

int main() {
  scanf("%d", &n);

  for(; n>=0; --n) {
    gets(line);
    length = strlen(line);

    for(i=0; i<length; ++i){
      if(isalpha(line[i])) {
        up = toupper(line[i]);
        count[up] = count[up] + 1;
      }
    }
  }

  for(std::map<char, int>::const_iterator it = count.begin(); it!=count.end(); ++it) {
    output.push_back(*it);
  }

  stable_sort(output.begin(), output.end(), greaterComparator());

  for(std::vector<std::pair<char, int> >::const_iterator it = output.begin(); it!=output.end(); ++it) {
    printf("%c %d\n", it->first, it->second);
  }
}
