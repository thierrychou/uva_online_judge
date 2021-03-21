#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cctype>
#include <map>
#include <string>

using namespace std;

char line[81];
char *token;
map<string, string> words;
map<string, string>::const_iterator it;
map<string, int> dict;

void toAnagram(string& word) {
  transform(word.begin(), word.end(), word.begin(), (int(*)(int))tolower);
  sort(word.begin(), word.end());
}

int main() {
  while(gets(line)!=NULL) {
    if(line[0] == '#') {
      break;
    }
    for(token = strtok(line, " "); token != NULL; token = strtok(NULL, " ")) {
      string word(token);

      string anagram(word);
      toAnagram(anagram);

      words.insert(pair<string, string>(word, anagram));
      ++dict[anagram];
    }
  }

  for(it = words.begin(); it != words.end(); ++it) {
    if(dict[it->second] == 1) {
      printf("%s\n", it->first.c_str());
    }
  }
}
