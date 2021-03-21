#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int t, c, v, i, cMax;
char url[101];
vector<pair<string, int> > container;

int main() {
  scanf("%d", &t);
  for(c=1; c<=t; ++c) {
    cMax = 0;
    container.clear();

    for(i=0; i<10; ++i) {
      scanf("%s %d", &url, &v);
      string str(url);
      container.push_back(make_pair(str, v));
      cMax = max(cMax, v);
    }

    printf("Case #%d:\n", c);
    for(vector<pair<string, int> >::const_iterator it=container.begin(); it!=container.end(); ++it) {
      if((*it).second == cMax) {
        printf("%s\n", (*it).first.c_str());
      }
    }
  }
}
