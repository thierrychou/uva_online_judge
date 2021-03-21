#include <cctype>
#include <cstdio>
#include <cstring>

int d_row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d_col[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool firstCase;
int tc, m, n, k;
char matrix[51][51], word[51];

inline bool dfsVisit(int x, int y, int dx, int dy) {
    int length = strlen(word);
    for(int i=1; i<length; ++i) {
	x += dx;
	y += dy;
	if(x<0 || y<0 || x>=m || y>=n) {
	    return false;
	} else if(tolower(matrix[x][y]) != tolower(word[i])) {
	    return false;
	}
    }
    return true;
}

inline bool dfs(int x, int y) {
    for(int i=0; i<8; ++i) {
	if(dfsVisit(x, y, d_row[i], d_col[i])) {
	    return true;
	}
    }
    return false;
}

int main() {
    firstCase = true;
    scanf("%d", &tc);
    while(tc--) {
	if(firstCase) {
	    firstCase = false;
	} else {
	    printf("\n");
	}
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; ++i) {
            scanf("%s", &matrix[i]);
        }
        scanf("%d", &k);
        for(int w=0; w<k; ++w) {
            scanf("%s", &word);
	    bool result = false;
            for(int i=0; i<m; ++i) {
                for(int j=0;j<n; ++j) {
	            if(tolower(matrix[i][j]) == tolower(word[0])) {
	                result = dfs(i,j);
		        if(result) {
		            printf("%d %d\n", i+1, j+1);
		            break;
		        }
	            }   
	        }
	        if(result) break;
            }
	}
    }
}
