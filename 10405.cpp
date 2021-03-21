#include <algorithm>
#include <cstdio>
#include <cstring>

int i, j, n1, n2;
char s1[1010], s2[1010];
int matrix[1010][1010];

inline int lcs_length() {
    for(i=0; i<=n1; ++i) matrix[i][0] = 0;
    for(i=0; i<=n2; ++i) matrix[0][i] = 0;

    for(i=1; i<=n1; ++i) {
        for(j=1; j<=n2; ++j) {
            if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
	    } else {
	       matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
	    }
        }
    }
    return matrix[n1][n2];
}

int main() {
    while(gets(s1)!=NULL && gets(s2)!=NULL) {
	n1 = strlen(s1);
	n2 = strlen(s2);
	printf("%d\n", lcs_length());
    }
}
