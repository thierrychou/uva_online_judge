#include <algorithm>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>

int i, j;
char line1[1001], line2[1001];
int matrix[1100][1100];

inline int lcs_length(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    for(i=0; i<=n1; ++i) matrix[i][0] = 0;
    for(i=0; i<=n2; ++i) matrix[0][i] = 0;

    for(i=1; i<=n1; ++i) {
        for(j=1; j<=n2; ++j) {
            if(v1[i-1].compare(v2[j-1])==0) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
	    } else {
	       matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
	    }
        }
    }
    return matrix[n1][n2];
}

inline void parse_line(const char* line, std::vector<std::string>& text) {
    char buf[21];
    int ptr = 0;
    for(int i=0; line[i]!=0; ++i) {
        if(isalnum(line[i])) {
	    buf[ptr++] = line[i];
	} else {
	    if(ptr>0) {
	        buf[ptr]=0;
                text.push_back(std::string(buf));
		ptr = 0;
	    }
	}
    }
    if(ptr>0) {
        buf[ptr]=0;
        text.push_back(std::string(buf));
    }
}

int main() {
    int tc = 0;
    while(gets(line1)!=NULL && gets(line2)!=NULL) {
	if(line1[0]==0 || line2[0]==0) {
	    printf("%2d. Blank!\n", ++tc);
	    continue;
	}

	std::vector<std::string> text1, text2;
	// parse into words
	parse_line(line1, text1);
	parse_line(line2, text2);

	printf("%2d. Length of longest match: %d\n", ++tc, lcs_length(text1, text2));
    }
}
