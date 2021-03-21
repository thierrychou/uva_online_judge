#include<cstdio>
#include<cstring>

long i, j, n, t, count[101];

int main() {
  setvbuf(stdin, NULL, _IOFBF, 30960 );
  setvbuf(stdout, NULL, _IOFBF, 1024000 );
  
  while(scanf("%d", &n) != EOF && n!=0) {
    memset(count, 0, sizeof(long)*101);
    //Input
    for(i=0 ;i<n ;++i) {
      scanf("%d", &t);
      ++count[t];
    }
    //Output
    bool firstItem = true;
    for(i=1; i<=100; ++i) {
      for(j=count[i]; j>0; --j) {
	if(firstItem) {
	  firstItem = false;
	  printf("%d", i);
	} else
	  printf(" %d", i);
      }
    }
    printf("\n");
  }
}

