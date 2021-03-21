#include <cstdio>

char s[2000010], t[2000010];
int i, j;

int main() {
    while(scanf("%s %s", &s, &t)!=EOF) {
	i=0;
        for(j=0; s[i]!=0 && t[j]!=0; ++j) {
	    if(s[i]==t[j]) {
		++i;
	    }
	}
	printf((s[i]==0) ? "Yes\n": "No\n");
    }
}
