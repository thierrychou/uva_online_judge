#include<stdio.h>
#include<algorithm>

struct sequence {
  char letters[51];
  int inversion;
};

sequence sequences[100];
int dataset, datasets, n, m, i;

inline bool compare(const sequence& a, const sequence& b) {
  return a.inversion < b.inversion;
}

int count_inversion(const char str[]) {
  int count = 0;
  for(int i=0; str[i]; ++i) {
    for(int j=i+1; str[j]; ++j) {
      if(str[i]>str[j]) {
	++count;
      }
    }	    
  }
  return count;
}

int main() {
  scanf("%d", &datasets);
  for(dataset=0; dataset<datasets; ++dataset) {
    scanf("%d %d", &n, &m);
    for(i=0; i<m; ++i) {
      scanf("%s", sequences[i].letters);
      sequences[i].inversion = count_inversion(sequences[i].letters);
    }
    std::stable_sort(sequences, sequences+m, compare);
    if(dataset!=0) printf("\n");
    for(i=0; i<m; ++i) {
      printf("%s\n", sequences[i].letters);
    }
  }
}
