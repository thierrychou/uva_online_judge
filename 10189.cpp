#include<stdio.h>

int field = 1;
int i, j, n, m;
char line[101];
int grid[100][100];

void increment(const int& x,const int& y){
  if(x<0 || y<0 || x>=n ||y>=m)
    return;

  if(grid[x][y] != -1)
    grid[x][y]++;
}

int main()
{
  while(scanf("%d %d", &n, &m)!=EOF){
    if(n==0 || m==0){
      return 0;
    }

    for(i=0; i<n; ++i){
      scanf("%s", line);
      for(j=0; j<m; ++j){
        if(line[j] == '*'){
          grid[i][j] = -1;
        }else{
          grid[i][j] = 0;
        }
      }
    }

    for(i=0; i<n; ++i){
      for(j=0; j<m; ++j){
        if(grid[i][j] == -1){
          increment(i-1, j-1);
          increment(i, j-1);
          increment(i+1, j-1);

          increment(i-1, j);
          increment(i+1, j);

          increment(i-1, j+1);
          increment(i, j+1);
          increment(i+1, j+1);
        }
      }
    }

    if(field!=1)
      printf("\n");

    printf("Field #%d:\n", field);
    for(i=0; i<n; ++i){
      for(j=0; j<m; ++j){
        if(grid[i][j]==-1)
          printf("%c", '*');
        else
          printf("%d", grid[i][j]);
      }
      printf("\n");
    }

    field++;
  }
}

