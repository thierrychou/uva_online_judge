#include <bitset>
#include <cmath>
#include <cstdio>

int n;
std::bitset<65001> is_prime;
bool is_carmichael[65001];

void sieve(int n) {
    is_prime.set();
    int length = sqrt(n);
    for(int i=2; i<=length; ++i) {
        if(is_prime[i]) {
	    for(int j=i*i; j<=n; j+=i) {
	        is_prime[j] = false;
	    }
	}
    }
}

inline int mod_pow(long long base, int exp, int mod) {
    long long r = 1;
    while(exp>0) {
        if(exp%2 == 1) {
	    r = (r * base) % mod;
	}
	exp >>= 1;
	base = (base*base) % mod;
    }
    return r;
}

bool carmichael_test(int n) {
    for(int a=2; a<n; ++a) {
        if(mod_pow(a,n,n) != a) return false;
    }
    return true;
}

int main() {
    sieve(65000);

    for(int i=2; i<=65000; ++i) {
	is_carmichael[i] = is_prime[i] ? false : carmichael_test(i);
    }
    while(scanf("%d", &n)!=EOF) {
        if(n==0) break;
	printf(is_carmichael[n] ? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n);
    }
}
