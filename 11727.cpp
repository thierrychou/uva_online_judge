#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int i, j, t, temp;
vector<int> s;

int main() {
  scanf("%d", &t);
  for(i=1; i<=t; ++i){
    s.clear();

    for(j=0; j<3; ++j) {
      scanf("%d", &temp);
      s.push_back(temp);
    }
    sort(s.begin(), s.end());
    printf("Case %d: %d\n", i, s[1]);
  }
}
