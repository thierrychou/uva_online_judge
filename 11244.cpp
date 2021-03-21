#include <cstdio>

int i,j,r,c;
char sky[101][101];

int shift_r[] = {-1,-1,-1, 0, 1, 1,  1,  0};
int shift_c[] = {-1, 0, 1, 1, 1, 0, -1, -1};

inline bool is_star(const int& i, const int& j) {
    int ptr_i, ptr_j;
    for(int p=0; p<8; ++p) {
        ptr_i = i + shift_r[p];
	ptr_j = j + shift_c[p];
	if( 0<=ptr_i && ptr_i<r
	 && 0<=ptr_j && ptr_j<c) {
	    if(sky[ptr_i][ptr_j] == '*') {
	        return false;
	    }
	}
    }
    return true;
}

int main() {
    while(scanf("%d %d", &r, &c) != EOF) {
	if(r==0 &&c==0) break;
        for(i=0; i<r; ++i) {
	    scanf("%s", sky[i]);
	}

	int count=0;
	for(i=0; i<r; ++i) {
	    for(j=0; j<c; ++j) {
	        if(sky[i][j]=='*' && is_star(i,j)) {
		    ++count;
		}
	    }
	}
	printf("%d\n", count);
    }
}
