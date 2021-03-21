#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int f, sum = 0;
		scanf("%d", &f);
		for (int j = 0; j < f; ++j) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			sum += a * c;
		}
		printf("%d\n", sum);
	}
}
