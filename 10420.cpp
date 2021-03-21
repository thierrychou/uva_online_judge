#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int n;
char str[80];
string line, cty, name;
int split;

set<string> countries;
multimap<string, string> conquests;

int main() {
  scanf("%d\n", &n);
  for(; n>0; --n) {
    getline(cin, line);

    split = line.find(' ');
    cty  = line.substr(0, split);
    name = line.substr(split+1, 100);

    countries.insert(cty);
    conquests.insert(pair<string, string>(cty, name));
  }

  for(set<string>::const_iterator it = countries.begin(); it!=countries.end(); it++) {
    set<string> uniqueNames;
    pair<multimap<string, string>::const_iterator, multimap<string, string>::const_iterator> p = conquests.equal_range(*it);

    for(multimap<string, string>::const_iterator it2 = p.first; it2!=p.second; it2++) {
      uniqueNames.insert(it2->second);
    }

    printf("%s %u\n", (*it).c_str(), uniqueNames.size());
  }
}

