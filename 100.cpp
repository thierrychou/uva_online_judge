#include <algorithm>
#include <cstdio>

int MAX = 1000000;
int array[1000001];

int inline cycleLength(int n) {
    if(n==1) return 1;
    if(n<MAX) {
        if(array[n]==0) {
            array[n] = 1 + cycleLength( (n%2 == 1) ? 3 * n + 1 : n / 2);
        }
        return array[n];
    } else {
	// Too big to cache.
	return 1 + cycleLength( (n%2 == 1) ? 3 * n + 1 : n / 2);
    }
}

int i,j,from,to,m;

int main() {
    while(scanf("%d %d", &i, &j)!=EOF) {
	from = std::min(i,j);
	to   = std::max(i,j);
	m = 0;
    	for(int x=from; x<=to; ++x) {
	    m = std::max(m, cycleLength(x));
	}
	printf("%d %d %d\n", i, j, m);
    }
}
