#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

int t,i,j, ptr;
char output[10001];

int main() {
    scanf("%d", &t);
    getchar();
    while(t--) {
	std::string line;
        std::getline(std::cin, line);
	double length = sqrt(line.size());
        if(floor(length)==length) {
	    ptr = 0;
	    for(i=0; i<length; ++i) {
	        for(j=0; j<length; ++j) {
		    output[ptr++] = line[i + j*length];
		}
	    }
	    output[ptr] = 0;
	    printf("%s\n", output);
	} else {
	    printf("INVALID\n");
	}
    }
}
