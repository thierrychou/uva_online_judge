#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <vector>

int n;

int main() {
    bool first = true;
    int budget, f;
    std::string name;

    while(std::cin>>n) {
	if(!first) {
	    printf("\n");
	} else {
	    first = false;
	}
	std::vector<std::string> names;
	std::map<std::string, int> m;

	for(int i=0; i<n; ++i) {
	    std::cin >> name;

	    names.push_back(name);
	    m[name] = 0;
	}
	for(int i=0; i<n; ++i) {
	    std::cin >> name >> budget >> f;

	    if(f<=0) {
		//m[name] += budget;
		continue;
	    } else {
	        int cost = budget/f;
	        m[name] += -cost*f;
	        for(int j=0; j<f; ++j) {
	            std::cin >> name;
		    m[name] += cost;
	        }
	    }
	}
	for(const std::string& s : names) {
	    printf("%s %d\n", s.c_str(), m[s]);
	}
    }
}
