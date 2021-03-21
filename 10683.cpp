#include <cstdio>

char l[9];
int h,m,s,c,r;

int main() {
    while(gets(l) != NULL) {
        h = 10 * (l[0]-'0') + l[1]-'0';
	m = 10 * (l[2]-'0') + l[3]-'0';
	s = 10 * (l[4]-'0') + l[5]-'0';
	c = 10 * (l[6]-'0') + l[7]-'0';
	r = ((h*60 + m)*60 + s)*100 + c;
	printf("%07d\n", r * 125 / 108);
    }
}

