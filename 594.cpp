#include <algorithm>
#include <cstdio>

int input, clone;

int main() {
    while(scanf("%d", &input)!=EOF) {
	clone = input;
        char* c = (char*)&clone;
	std::swap(c[0], c[3]);
	std::swap(c[1], c[2]);
	printf("%d converts to %d\n", input, clone); 
    }
}
