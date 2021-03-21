#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>

int l, n, i;
int cut[55], matrix[55][55];

int solution(int l, int r) {
    if(l+1==r) return 0;
    if(matrix[l][r]!=-1) return matrix[l][r];

    int cost = INT_MAX;
    for(int x=l+1; x<r; ++x) {
        cost = std::min(cut[r] - cut[l] +
		        solution(l,x) + solution(x,r), cost);
    }
    matrix[l][r] = cost;
    return cost;
}

int main() {
    while(scanf("%d", &l)!=EOF) {
        if(l==0) break;
        scanf("%d", &n);
	for(i=1; i<=n; ++i) scanf("%d", &cut[i]);
	cut[0] = 0;
	cut[n+1] = l;
	memset(matrix, -1, sizeof(matrix));
	printf("The minimum cutting is %d.\n", solution(0, n+1));
    }
}
