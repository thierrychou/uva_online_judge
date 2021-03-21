#include <cstdio>

int n, i, period;
char s[81];

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%s", &s);
	period = 1;
	for(i=0; s[i]!=0; ++i) {
	    while(s[i] != s[i%period]) ++period;
	}
	if(i%period==0) {
	    printf("%d\n", period);
	} else {
	    printf("%d\n", i);
	}
	if(n>0) {
	    printf("\n");
	}
    }
}
