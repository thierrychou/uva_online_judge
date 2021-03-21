#include <cstdio>
#include <cstring>

char line[100];

int v[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

inline int decode(const char* line) {
    int r = 0;
    int digit = 0;
    for(int i=strlen(line); line[i]>=0; --i) {
	if(line[i] == ' ')       digit++;
	else if(line[i] == 'o')  r += v[digit++];
    }
    return r;
}

int main() {
    while(gets(line)!=NULL) {
	int c = decode(line);
	if(c!=0) putchar((char)c);
    }
}
