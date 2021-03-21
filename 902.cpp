#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>

int n;

int main() {
    std::string text;
    while(std::cin >> n >> text) {
	int count_max = -1;
	std::map<std::string, int> m;
        for(int i=0; i<=text.size()-n; ++i) {
	    std::string s = text.substr(i, n);
	    m[s]++;
	    count_max = std::max(count_max, m[s]);
	}
	for(std::map<std::string, int>::iterator it=m.begin(); it!=m.end(); it++) {
	    if(it->second == count_max) {
	        printf("%s\n", it->first.c_str());
	    }
	}
    }
}
