#include <cstdio>
#include <cstring>

#define MAX_CENTS 30000

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
	if(dp[amount]==1) {
            printf("There is only 1 way to produce %d cents change.\n", amount);
	} else {
            printf("There are %.f ways to produce %d cents change.\n", dp[amount], amount);
	}
    }
}

