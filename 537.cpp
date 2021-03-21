#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>

double p, u, i;
bool hasP, hasU, hasI;
std::string line;
int tc;

inline double getV(size_t pos) {
    std::string str;
    while(!isalpha(line[pos+1])) {
	str += line[++pos];
    }
    double v = atof(str.c_str());
    switch(line[pos+1]) {
    case 'm': v*=0.001; break;
    case 'k': v*=1000; break;
    case 'M': v*=1000000; break;
    }
    return v;
}

inline void parse(size_t pos) {
    switch(line[pos-1]) {
    case 'P': hasP = true; p = getV(pos); break;
    case 'U': hasU = true; u = getV(pos); break;
    case 'I': hasI = true; i = getV(pos); break;
    }
}

int main() {
    scanf("%d\n", &tc);
    for(int t=1; t<=tc; ++t) {
	p = u = i = 0;
	hasP = hasU = hasI = false;

        std::getline(std::cin, line);
	parse(line.find_first_of('='));
	parse(line.find_last_of('='));

	printf("Problem #%d\n", t);
	if(!hasP) {
	    printf("P=%.2lfW\n\n", u*i);
	} else if(!hasU) {
	    printf("U=%.2lfV\n\n", p/i);
	} else {
	    printf("I=%.2lfA\n\n", p/u);
	}
    }
}
