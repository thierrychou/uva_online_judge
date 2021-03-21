#include <cstdio>
#include <cstring>

int t, n, m, p;
int count[33];

int main() {
    scanf("%d", &t);
    while(t--) {
	memset(count, 0, sizeof(count));
        scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i) {
	    for(int j=0; j<n; ++j) {
                scanf("%d", &p);
		if(p==1) {
		    ++count[j];
		}
	    }
	}
	int total=1;
	for(int i=0; i<n; ++i) {
	    if(count[i]!=0) total *= count[i];
	}
	printf("%d\n", total);
    }
}
