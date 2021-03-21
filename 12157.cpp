#include <cstdio>
#include <cmath>

int tc,t,n,m,j,c;

int main() {
    scanf("%d", &tc);
    for(t=1; t<=tc; ++t) {
        scanf("%d", &n);
	m = j = 0;
	while(n--) {
	    scanf("%d", &c);
	    m += (c+30)/30;
	    j += (c+60)/60;
	}
	m *= 10;
	j *= 15;
	if(m<j) {
	    printf("Case %d: Mile %d\n", t, m);
	} else if(j<m) {
	    printf("Case %d: Juice %d\n", t, j);
	} else {
	    printf("Case %d: Mile Juice %d\n", t, m);
	}
    }
}
