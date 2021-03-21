#include <cstdio>

char line[100];
char mapping[2][33];

int main() {
    gets(mapping[0]);
    gets(mapping[1]);
    while(gets(line)!=NULL) {
	int mode=0;
        for(int i=0; line[i]!=0; i+=5) {
	    int code=0;
	    for(int x=0; x<5; ++x) {
	        code = code*2 + line[i+x] - '0';
	    }
	    if(code==27) {
		mode = 0;
	    } else if(code==31) {
		mode = 1;
	    } else {
	        putchar(mapping[mode][code]);
	    }
	}
	putchar('\n');
    }
}
