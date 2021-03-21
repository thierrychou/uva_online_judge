#include<algorithm>
#include<cstdio>
#include<utility>

bool first;
int i;
char line[1001];

inline bool compare(const std::pair<char, int>& a, const std::pair<char, int>& b) {
  if(a.second==b.second)
    return a.first > b.first;
  else
    return a.second < b.second;
}

int main() {
  first = true;
  while(gets(line)!=NULL) {
    //init
    std::pair<char, int> freq[96];
    for(i=0; i<96; ++i) {
      freq[i].first = i+32;
      freq[i].second = 0;
    }
    //read
    for(i=0; line[i]!=0; ++i) {
      freq[line[i]-32].second++;
    }
    //sort
    std::sort(freq, freq+96, compare);
    //display
    if(!first) printf("\n");
    first = false;
    for(i=0; i<96; ++i) {
      if(freq[i].second==0) continue;
      printf("%d %d\n", freq[i].first, freq[i].second);
    }
  }
}
