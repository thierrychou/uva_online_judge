#include <cstdio>

int n, e, balance;

int main() {
    int t = 0;
    while(scanf("%d", &n)!=EOF && n!=0) {
	balance = 0;
        while(n--) {
	    scanf("%d", &e);
	    if(e>0) ++balance;
	    else --balance;
	}
	printf("Case %d: %d\n", ++t, balance);
    }
}
