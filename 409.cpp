#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <set>
#include <string>
#include <vector>

int k,e, excuseCount, maxCount;
int i, length, setCount;
char line[71];
char* ptr;

inline std::string::const_iterator next_start(const std::string& str, std::string::const_iterator it) {
    if(it>str.end()) return str.end();
    while(it != str.end() && !isalpha(*it)) {
        ++it;
    }
    return it;
}
inline std::string::const_iterator next_end(const std::string& str, std::string::const_iterator it) {
    if(it>str.end()) return str.end();
    while(it != str.end() && isalpha(*it)) {
        ++it;
    }
    return it;
}

int main() {
    std::set<std::string> keywords;
    std::vector<std::string> excuses;
    std::vector<int> count;

    excuses.reserve(21);
    count.reserve(21);

    setCount = 0;
    while(scanf("%d %d", &k, &e) !=EOF) {
    maxCount = 0;
    while(k--) {
        scanf("%s\n", line);
	keywords.insert(line);
    }
    while(e--) {
        gets(line);
	excuses.push_back(line);

	excuseCount = 0;
	
	std::string str(line);
	std::string::const_iterator left = next_start(str, str.begin());
	std::string::const_iterator right = next_end(str, left+1);
	do {
	    std::string loweredStr(left,right);
	    std::transform(left, right, loweredStr.begin(), ::tolower);
	    if(keywords.find(loweredStr) != keywords.end()) {
	        ++excuseCount;
	    }
	    left = next_start(str, right+1);
	    right = next_end(str, left+1);
	} while(left != str.end());
	count.push_back(excuseCount);
	maxCount = std::max(maxCount, excuseCount);
    }

    printf("Excuse Set #%d\n", ++setCount);
    length = count.size();
    for(i=0; i<length; ++i) {
	if(count[i]==maxCount) {
            printf("%s\n", excuses[i].c_str());
	}
    }
    printf("\n");

    keywords.clear();
    excuses.clear();
    count.clear();
    }
}
