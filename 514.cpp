#include<cstdio>
#include<stack>
#include<queue>

bool first_block;
int n, i;
int target[1001];

int main() {
  while(scanf("%d", &n) != EOF && n!=0) {
    //read target line.
    while(scanf("%d", &target[0]) != EOF) {
      if(target[0] == 0) {
        printf("\n");
	break;
      }
      for(i=1; i<n; ++i) scanf("%d", &target[i]);

      //init a
      std::queue<int> a;
      std::stack<int> s;
      for(i=1; i<=n; ++i) a.push(i);

      i=0;
      while(i<n) {
        if(!s.empty() && (s.top() == target[i])) {
          //found.
          ++i;
          s.pop();
        } else if(!a.empty()) {
          //get one more fron a
          s.push(a.front());
          a.pop();
        } else {
          // unable to find.
  	  break;
        }
      }
      if(i==n) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
}
