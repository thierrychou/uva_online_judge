#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>

int t, ptr;
char list[10001], line[10001];

inline void remove_space(const char* str) {
    int ptr=0;
    for(int i=0; str[i]!=0; ++i) {
	if(isalpha(str[i])) {
            list[ptr++] = str[i];
	}
    }
    list[ptr]=0;
}

inline int is_square_palindrome(const char* str) {
    int length = strlen(str);
    int square = sqrt(length);
    if(square * square != length) return -1;

    std::string s1, s2, s3, s4;
    for(int i=0; i<square; ++i) {
        s1.push_back(str[i]);
	s2.push_back(str[0 + i*square]);
	s3.push_back(str[(square-1)*square + (square-i-1)]);
	s4.push_back(str[(square-i-1)*square + (square-1)]);
    }
    if(s1.compare(s2)==0 &&
       s2.compare(s3)==0 &&
       s3.compare(s4)==0) {
        return square;
    } else {
        return -1;
    }
}

int main() {
    scanf("%d\n", &t);
    for(int tc=1; tc<=t; ++tc) {
	remove_space(gets(line));
        int s = is_square_palindrome(list);
        printf("Case #%d:\n", tc);
        if(s>0) {
            printf("%d\n", s);
        } else {
            printf("No magic :(\n");
        }
    }
}
