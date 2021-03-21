#include <stdio.h>

int main() {
	int n, a, b, t;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		t = a - b;
		if (t == 0) {
			printf("=\n");
		} else if (t > 0) {
			printf(">\n");
		} else {
			printf("<\n");
		}
	}
}
