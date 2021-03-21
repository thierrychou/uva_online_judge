#include <algorithm>
#include <cstdio>
#include <cstdlib>

int tc, r, i, m, total, s[501];

int main() {
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &r);
	for(i=0; i<r; ++i) scanf("%d", &s[i]);

	std::sort(s, s+r);
	m = s[r/2];

	total = 0;
	for(i=0; i<r; ++i) total += abs(m-s[i]);
	printf("%d\n", total);
    }
}
