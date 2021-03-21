#include <cstdio>

int n,m;
char x2[200];

inline int count(int m) {
    int c = 0;
    while(m>0) {
        if(m&1) ++c;
	m = m >> 1;
    }
    return c;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &m);
        printf("%d", count(m));

	sprintf(x2, "%d", m);
	sscanf(x2, "%x", &m);
	printf(" %d\n", count(m));
    }
}
