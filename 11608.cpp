#include <cstdio>

int i, available, tc;
int p[13], r[12];

int main() {
    tc = 0;
    while(scanf("%d", &p[0])!=EOF && p[0]>=0) {
	printf("Case %d:\n", ++tc);

        for(i=1; i<=12; ++i) scanf("%d", &p[i]);
	for(i=0; i<12; ++i) scanf("%d", &r[i]);
        
	available = 0;
        for(i=0; i<12; ++i) {
            available += p[i];
            if(available >= r[i]) {
	        available -= r[i];
                printf("No problem! :D\n");
	    } else {
	        printf("No problem. :(\n");
	    }
	}
    }
}

