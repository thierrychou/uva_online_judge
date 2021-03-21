#include <cstdio>

int b,n,i,d,c,v,r[21];
bool bail;

int main() {
    while(scanf("%d %d", &b, &n)!=EOF) {
	if(b==0 && n==0) break;

        for(i=0;i<b;++i) scanf("%d", &r[i]);
	for(i=0;i<n;++i) {
	    scanf("%d %d %d", &d, &c, &v);
	    r[d-1] -= v;
	    r[c-1] += v;
	}
	bail = false;
	for(i=0;i<b;++i) {
	    if(r[i]<0) {
	        bail = true;
		break;
	    }
	}
	printf( bail ? "N\n" : "S\n");
    }
}
