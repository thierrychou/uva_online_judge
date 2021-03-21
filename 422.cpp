#include <cstdio>
#include <cstring>

int d_row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d_col[] = {-1, 0, 1, 1, 1, 0, -1, -1};


int l, endX, endY;
char matrix[101][101], word[101];

inline bool dfsVisit(int x, int y, int dx, int dy) {
    int length = strlen(word);
    for(int i=1; i<length; ++i) {
	x += dx;
	y += dy;
	if(x<0 || y<0 || x>=l || y>=l) {
	    return false;
	} else if(matrix[x][y]!=word[i]) {
	    return false;
	}
    }
    endX = x;
    endY = y;
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
    scanf("%d", &l);
    for(int i=0; i<l; ++i) {
        scanf("%s", &matrix[i]);
    }
    while(scanf("%s", &word)!=EOF) {
        if(word[0]=='0') {
	    break;
	}
	bool result = false;
	for(int i=0; i<l; ++i) {
            for(int j=0;j<l; ++j) {
	        if(matrix[i][j] == word[0]) {
	            result = dfs(i,j);
		    if(result) {
		        printf("%d,%d %d,%d\n", i+1, j+1, endX+1, endY+1);
		        break;
		    }
	        }
	    }     
	    if(result) break;
         }
	 if(!result) {
	     printf("Not found\n");
	 }
    }
}
