#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int i, j, n, len, test=0;
char line[1000005];
int check[1000005];

int main() {
  while(gets(line)) {
    len = strlen(line);
    if(len==0) break;

    check[0] = (line[0]=='0') ? 0 : 1;
    for(i=1; i<len; ++i) {
      check[i] = (line[i]=='0') ? check[i-1] : check[i-1] + 1;
    }

    scanf("%d", &n);

    if(n>0)
      printf("Case %d:\n", ++test);

    for(; n>0; --n) {
      scanf("%d %d", &i, &j);

      if(i>j) {
        swap(i, j);	      
      }

      if(line[i]=='0' && line[j]=='0' && check[i]==check[j]) {
        printf("Yes\n");
      } else if(line[i]=='1' && line[j]=='1' && (check[j]-check[i]) == (j-i)) {
	printf("Yes\n");
      } else {
        printf("No\n");
      }
    }

    getchar();
  }
}

