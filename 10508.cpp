#include <cstdio>
#include <cstring>

int n, l, i, j, diff;
char word[3001][3001], temp[3001];

int main() {
    while(scanf("%d %d", &n, &l)!=EOF) {
        scanf("%s", word[0]);
	for(i=0; i<n-1; ++i) {
	    scanf("%s", temp);
	    diff = 0;
	    for(j=0; j<l; ++j) {
	        if(temp[j]!=word[0][j]) {
		 diff++;
		}
	    }
	    strcpy(word[diff], temp);
	}
	for(i=0; i<n; ++i) {
	    printf("%s\n", word[i]);
	}
    }
}
