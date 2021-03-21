#include <cstdio>
#include <cstdlib>

int a, b, p;

int main() {
    while(scanf("%d %d", &a, &b)!=EOF && (a!=-1 && b!=-1)) {
        p = abs(a-b);
	if(p>50) p = 100 - p;
	printf("%d\n", p);
    }
}

