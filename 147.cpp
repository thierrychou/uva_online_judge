#include <cmath>
#include <cstdio>
#include <cstring>

int changes[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
double dp[6001];

void count() {
    int sum = 6000;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<11; ++i) {
        for(int j=changes[i]; j<=sum; ++j) {
  	    dp[j] += dp[ j-changes[i] ];
	}
    }
}

int main() {
    count();
    float amount;
    while(scanf("%f", &amount)!=EOF) {
	if(amount==0) break;
        printf("%6.2f%17.lf\n", amount, dp[(int)round(amount*20)]);
        
    }
}

