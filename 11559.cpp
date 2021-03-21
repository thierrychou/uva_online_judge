#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

int n,b,h,w,p,a;
int i, minCost, cost;
bool found;

int main() {
  while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
    found = false;
    minCost = INT_MAX;
    for(; h>0; --h) {
      scanf("%d", &p);
      cost = n*p; 
      for(i=0; i<w; ++i) {
        scanf("%d", &a);
        if(cost<=b && n<=a) {
          minCost = min(minCost, cost);
          found = true;
        }
      }
    }
    if(!found) {
      printf("stay home\n");
    } else {
      printf("%d\n", minCost);
    }
  }
}
