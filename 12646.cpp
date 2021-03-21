#include <cstdio>
#include <cstdlib>

int v[3];

inline int count(int c) {
    int t=0;
    for(int i=0; i<3; ++i) {
	if(v[i]==c)
            t++;
    }
    return t;
}
inline int getIndex(int c) {
    for(int i=0; i<3; ++i) {
	if(v[i]==c) return i;
    }
}

int main() {
    while(scanf("%d %d %d", &v[0], &v[1], &v[2])!=EOF) {
        int count1 = count(1);
	int count0 = count(0);
	if(abs(count1-count0)==1) {
	    int c = (count1>count0) ? 0 : 1;
	    printf("%c\n", 'A' + getIndex(c));
	} else {
	    printf("*\n");
	}
    }
}
