#include <algorithm>
#include <cstdio>
#include <cstring>

char a[1001], b[1001];
int c_a[26], c_b[26];
int i,j;

int main() {
    while(gets(a) && gets(b)) {
	memset(c_a, 0, sizeof(c_a));
	memset(c_b, 0, sizeof(c_b));

        for(i=0; a[i]; ++i) c_a[a[i]-'a']++;
	for(i=0; b[i]; ++i) c_b[b[i]-'a']++;

	for(i=0; i<26; ++i) {
	    j=std::min(c_a[i], c_b[i]);
	    while(j--) {
	        putchar(i+'a');
	    }
	}
	printf("\n");
    }
}

