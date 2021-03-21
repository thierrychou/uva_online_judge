#include <algorithm>
#include <cstdio>

int i, j, n1, n2, tc;
int tower1[110], tower2[110];
int matrix[110][110];

int lcs_length() {
    for(i=0; i<=n1; ++i) matrix[i][0] = 0;
    for(i=0; i<=n2; ++i) matrix[0][i] = 0;

    for(i=1; i<=n1; ++i) {
        for(j=1; j<=n2; ++j) {
            if(tower1[i-1] == tower2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
	    } else {
	       matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
	    }
        }
    }
    return matrix[n1][n2];
}

int main() {
    tc =0;
    while(scanf("%d %d", &n1, &n2)!=EOF) {
        if(n1==0&&n2==0) break;
	for(i=0; i<n1; ++i) scanf("%d", &tower1[i]);
	for(i=0; i<n2; ++i) scanf("%d", &tower2[i]);
	printf("Twin Towers #%d\n", ++tc);
	printf("Number of Tiles : %d\n\n", lcs_length());
    }
}
