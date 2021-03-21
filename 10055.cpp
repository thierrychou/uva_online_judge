#include <stdio.h>

int main() {
	unsigned long i;
	unsigned long j;
	while (scanf("%lu %lu", &i, &j) != EOF) {
		if (i > j)
			printf("%lu\n", i - j);
		else
			printf("%lu\n", j - i);
	}
}
