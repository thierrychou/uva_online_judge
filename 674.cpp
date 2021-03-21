#include <cstdio>
#include <cstring>

#define MAX_CENTS 7489

int changes[5] = {1, 5, 10, 25, 50};
double dp[MAX_CENTS+1];

void count() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<5; ++i) {
        for(int j=changes[i]; j<=MAX_CENTS; ++j) {
  	    dp[j] += dp[ j-changes[i] ];
	}
    }
}

int main() {
    count();
    int amount;
    while(scanf("%d", &amount)!=EOF) {
        printf("%.lf\n", dp[amount]);
    }
}

