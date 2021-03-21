#include <cstdio>
#include <iostream>
#include <set>
#include <string>

inline bool is_consistent(const std::string& str, const std::set<std::string>& dictionary) {
    for(int i=1; i<str.length(); ++i) {
        std::string prefix = str.substr(0, i);
	if(dictionary.find(prefix)!=dictionary.end()) {
	    return false;
	}
    }
    return true;
}

int t, n;

int main() {
    scanf("%d", &t);
    while(t--) {
	std::set<std::string> numbers;
        scanf("%d\n", &n);
	while(n--) {
	    std::string number;
	    getline(std::cin, number);
	    numbers.insert(number);
	}
	bool consist = true;
	for(std::set<std::string>::iterator it=numbers.begin(); it!=numbers.end(); it++) {
	    consist = is_consistent(*it, numbers);
	    if(!consist) {
	        break;
	    }
	}
	printf( consist ? "YES\n" : "NO\n");
    }
}
