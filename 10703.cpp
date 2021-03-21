#include<stdio.h>
#include<cstring>
#include<algorithm>

bool board[501][501];
int w, h, n, x1, x2, y1, y2, i, j, count;

int main() {
  while(scanf("%d %d %d", &w, &h, &n)!=EOF) {
    if(w==0 && h==0 && n==0) return 0;

    for(i=1; i<=w; ++i) {
      std::memset(board[i], false, sizeof(board[i]));
    }

    while(n--) {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

      if(x1>x2) std::swap(x1,x2);
      if(y1>y2) std::swap(y1,y2);

      for(i=x1; i<=x2; ++i) {
	for(j=y1; j<=y2; ++j) {
	  board[i][j]=true;
	}
      }
    }

    count = 0;
    for(i=1; i<=w; ++i) {
      for(j=1; j<=h; ++j) {
	if(!board[i][j]) ++count;
      }
    }

    if(count==0) printf("There is no empty spots.\n");
    else if(count==1) printf("There is one empty spot.\n");
    else printf("There are %d empty spots.\n", count);
  }
}
