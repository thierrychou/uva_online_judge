#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int number, length, tc, i;

int main() {
    std::string line;

    scanf("%d", &tc);
    while(tc--) {
	std::getline(std::cin, line);
	std::getline(std::cin, line);
	std::getline(std::cin, line);
	
	std::vector<int> v;
	std::istringstream in(line);
	while(in >> number) v.push_back(number);
	length = v.size();
	std::vector<std::string> p(length);
	for(i=0; i<length; ++i) {
	    std::string s;
	    std::cin >> s;
	    p[v[i]-1] = s;
	}
	for(std::vector<std::string>::const_iterator it=p.begin(); it!=p.end(); ++it) {
	    printf("%s\n", it->c_str());
	}
	if(tc!=0) {
	    printf("\n");
	}
    }
}
