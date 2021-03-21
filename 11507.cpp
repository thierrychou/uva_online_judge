#include <cstdio>
#include <cstring>

int l, direction;
char decision[3];

char ind[6][3] = {"+y", "-y", "+z", "-z", "+x", "-x"};

int matrix[6][4] = {
    { 5, 4, 0, 0 },
    { 4, 5, 1, 1 },
    { 2, 2, 5, 4 },
    { 3, 3, 4, 5 },
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 }
};

int find_index(const char* d) {
  for(int i=0; i<4; ++i) {
    if(strcmp(d, ind[i])==0) return i;
  }
  return -1; //ERROR
}


int main() {
  while(scanf("%d", &l)!=EOF) {
    if(l==0) break;
    direction = 4;
    for(int i=0; i<l-1; ++i) {
      scanf("%s", &decision);
      if(strcmp(decision, "No")==0) continue;
      direction = matrix[direction][find_index(decision)];
    }
    printf("%s\n", ind[direction]);
  }
}
