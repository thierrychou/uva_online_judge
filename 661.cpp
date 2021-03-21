#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,c,i, maxLoading, sequence=1, tmp, loading;
bool devices[21], blown;

int main() {
  vector<int> consumptions;

  while(scanf("%d %d %d", &n, &m, &c) != EOF) {
    if(n==0 && m==0 && c==0) return 0;

    consumptions.clear();
    blown = false;
    maxLoading = 0;
    loading = 0;

    for(i=0;i<n;++i) {
      scanf("%d", &tmp);
      consumptions.push_back(tmp);
      devices[i] = false;
    }

    for(i=0;i<m;++i) {
      scanf("%d", &tmp);
      tmp--;
      if(!blown) {
        if(devices[tmp]) {
          devices[tmp] = false;
          loading -= consumptions[tmp];
        } else {
          devices[tmp] = true;
          loading += consumptions[tmp];
          maxLoading = std::max(loading, maxLoading);
          if(loading>c) {
            blown = true;
          }
        }
      }
    }
    printf("Sequence %d\n", sequence++);
    if(blown) {
      printf("Fuse was blown.\n\n");
    } else {
      printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxLoading);
    }
  }
}
