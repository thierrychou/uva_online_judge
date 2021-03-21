#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int n, cols, rows;
size_t longest;
char line[61];
std::string list[101];

int main() {
    while(scanf("%d", &n) != EOF) {
        longest = 0;
	for(int i=0; i<n; ++i) {
	    std::cin >> list[i];
            longest = std::max(longest, list[i].size());
        }
	std::sort(list, list + n);

	longest += 2;
	cols = 62 / longest;
	rows = ceil((double)n / (double)cols);

	printf("------------------------------------------------------------\n");
	for(int r=0; r<rows; ++r) {
	    for(int j=r; j<n; j+=rows) {
	        printf("%s", list[j].c_str());
		if(j+rows<n) {
		    printf("%s", std::string(longest-list[j].size(), ' ').c_str());
		}
	    }
	    printf("\n");
	}
    }
}
