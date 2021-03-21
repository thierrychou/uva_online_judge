#include <cstdio>

int n;

int main() {
    while(scanf("%d", &n) == 1) {
        int v=n;
	int d=1;
	while(v>d) {
	    v -= d++;
	}
        int a = (d%2) ? d - v + 1 : v;
        int b = d - a + 1;
        printf("TERM %d IS %d/%d\n", n, a, b);
    }
}

