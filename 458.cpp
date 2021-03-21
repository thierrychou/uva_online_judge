#include <stdio.h>

int main() {
	char c;
	while ((c = getchar()) != EOF) {
		(c == '\n') ? putchar(c) : putchar(c - 7);
	}
}
