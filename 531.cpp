#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int i, j;
int matrix[110][110];

inline int lcs_length(const std::vector<int>& v1, const std::vector<int>& v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    for(i=0; i<=n1; ++i) matrix[i][0] = 0;
    for(i=0; i<=n2; ++i) matrix[0][i] = 0;

    for(i=1; i<=n1; ++i) {
        for(j=1; j<=n2; ++j) {
            if(v1[i-1] == v2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
	    } else {
	       matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
	    }
        }
    }
    return matrix[n1][n2];
}

void backtrack(std::stack<int>& s, const std::vector<int>& v1, const std::vector<int>& v2, int i, int j) {
    if(i==0 || j==0) return;
    if(v1[i-1]==v2[j-1]) {
	s.push(v1[i-1]);
        backtrack(s, v1, v2, i-1, j-1);
    } else {
	if(matrix[i][j-1]>matrix[i-1][j]) {
	    backtrack(s, v1, v2, i, j-1);
	} else {
	    backtrack(s, v1, v2, i-1, j);
	}
    }
}

int main() {
    int index = 0, input=0;
    std::map<std::string, int> m;
    std::map<int, std::string> reverse_m;
    std::string word;
    std::vector<int> text1, text2;

    while(std::cin >> word) {
	if(word[0] == '#') {
	    input++;
	    if(input!=2) continue;
	}
	if(input==2) {
	    lcs_length(text1, text2);
	    std::stack<int> s;
	    backtrack(s, text1, text2, text1.size(), text2.size());
	    if(!s.empty()) {
      		printf("%s", reverse_m[s.top()].c_str());
		s.pop();
	    }
	    while(!s.empty()) {
		printf(" %s", reverse_m[s.top()].c_str());
		s.pop();
	    }
	    printf("\n");

	    //reset
	    input=0;
	    m.clear();
	    reverse_m.clear();
	    text1.clear();
	    text2.clear();
	} else {
	    if(m.find(word) == m.end()) {
	        m[word] = index;
		reverse_m[index] = word;
	        index++;
	    }
	    if(input==0) {
		text1.push_back(m[word]);
	    } else {
		text2.push_back(m[word]);
	    }
	}
    }
}
