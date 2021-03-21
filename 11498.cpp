#include <stdio.h>

int k,n,m,x,y;

int main(){
  while(true) {
    scanf("%d", &k);
    if(k==0){
      return 0;
    }
    scanf("%d %d", &n, &m);
    for(; k>0; --k) {
      scanf("%d %d", &x, &y);
      if(x==n||y==m) {
        printf("divisa\n");
      }else if(x<n && y>m) {
        printf("NO\n");
      }else if(x>n && y>m) {
        printf("NE\n");
      }else if(x>n && y<m) {
        printf("SE\n");
      }else {
        printf("SO\n");
      }
    }
  }
}
