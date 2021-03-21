#include<cstdio>
#include<cstring>

int bit,i,j,col_count,row_count,n,corrupt_col,corrupt_row;
int sum_col[100], sum_row[100];

int main() {
  while(scanf("%d", &n)!=EOF && n!=0) {
    memset(sum_col, 0, sizeof(sum_col));
    memset(sum_row, 0, sizeof(sum_row));
    for(i=0 ;i<n; ++i) {
      for(j=0; j<n; ++j) {
        scanf("%d", &bit);
	if(bit==0) continue;
        sum_col[i] += bit;
        sum_row[j] += bit;
      }
    }
    col_count=0;
    row_count=0;
    for(i=0;i<n;++i) {
      if(sum_col[i]&1) {
        ++col_count;
	corrupt_col = i;
      }
      if(sum_row[i]&1) {
        ++row_count;
	corrupt_row = i;
      }
    }
    if(col_count==row_count && row_count==0) {
      printf("OK\n");
    } else if(col_count==1 && row_count==1) {
      printf("Change bit (%d,%d)\n", corrupt_col+1, corrupt_row+1);
    } else {
      printf("Corrupt\n");
    }
  }
}
