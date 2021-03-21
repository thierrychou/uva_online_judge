#include <algorithm>
#include <cstdio>

int t,n,x,min_p,max_p;

int main() {
    scanf("%d", &t);
    while(t--) {
	min_p = 100;
	max_p = -1;
        scanf("%d", &n);
	while(n--) {
	    scanf("%d", &x);
	    min_p = std::min(min_p, x);
	    max_p = std::max(max_p, x);
	}
	printf("%d\n", (max_p - min_p)*2);
    }
}
