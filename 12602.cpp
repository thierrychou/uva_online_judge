#include <cstdio>
#include <cstdlib>

inline int lval(const char* s) {
    return 676*(s[0]-'A') + 26*(s[1]-'A') + (s[2]-'A');
}

int n, d;
char l[4];

int main() {
    scanf("%d", &n);
    while(n--) {
	scanf("%3s-%d", &l, &d);
	printf((abs(lval(l) - d)<=100) ? "nice\n" : "not nice\n");
    }
}
