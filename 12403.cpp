#include <cstdio>

char o[7];
int t, k;
long balance;

int main() {
    balance = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", &o);
        if(o[0] == 'd') {
	    scanf("%d", &k);
	    balance += k;
	} else {
	    printf("%ld\n", balance);
	}
    }
}
