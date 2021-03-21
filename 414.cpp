#include<algorithm>
#include<cstdio>
#include<climits>

int n, i, j, count, total, min_count;
char line[26];

int main() {
  while(scanf("%d\n", &n)!=EOF && n!=0) {
    total = 0; min_count = INT_MAX;
    for(i=0;i<n;++i) {
      gets(line);
      
      count = 0;
      for(j=0;line[j]!='\0';++j)
        if(line[j]==' ') ++count;
      total += count;
      min_count = std::min(min_count, count);
    }
    printf("%d\n", total - min_count*n);
  }
}
