#include <cctype>
#include <cstdio>
#include <cstring>

int i, length, frequency[81];
char *p, line[65536];

inline void reset() {
    length = 0;
    memset(frequency, 0, sizeof(frequency));
}

int main() {
    reset();
    while(gets(line)) {
        if(line[0]=='#') {
	    for(i=1; i<=80; ++i) {
	        if(frequency[i]!=0) {
		    printf("%d %d\n", i, frequency[i]);
		}
	    }
	    printf("\n");
	    reset();
	}
	if(line[0]==0) continue;
	for(p=line; *p; ++p) {
	    if(isalpha(*p)) length++;
	    else if(*p!='\'' && *p!='-') {
	        frequency[length]++;
		length=0;
	    }
	}
	if(p[-1] != '-') {
	    frequency[length]++;
	    length=0;
	}
    }
}
