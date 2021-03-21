#include <cstdio>
#include <set>
#include <string>
#include <iostream>

int main() {
    std::set<std::string> dictionary;
    std::string word;
    while(std::cin>>word) {
        dictionary.insert(word);
    }
    for(std::set<std::string>::iterator it=dictionary.begin(); it!=dictionary.end(); it++) {
	std::string str = *it;
	for(int i = str.length()-1; i>=1; --i) {
    	    std::string a = str.substr(0,i);
	    std::string b = str.substr(i);
	    if(dictionary.find(a)!=dictionary.end() && dictionary.find(b)!=dictionary.end()) {
	        printf("%s\n", str.c_str());
	        break;
	    }
	}
    }
}
