#include <cctype>
#include <cstdio>
#include <list>
#include <string>
#include <iostream>

int main() {
    std::string buf;
    buf.reserve(500000);

    std::string word;
    word.reserve(60);

    std::list<std::string> lookup;

    std::string line;
    while(std::getline(std::cin, line)) {
	if(line.size()==1 && line[0]=='0') break;
        buf.append(line);
	buf.append("\n");
    }

    for(auto it=buf.cbegin(); it!=buf.cend(); ++it) {
	char c = *it;
        if(isalpha(c)) {
	    putchar(c);
	    word+=c;
	} else {
	    if(!word.empty()) {
	        lookup.push_front(word);
		word.clear();
	    }

	    if(isdigit(c)) {
		int num=0;
		for(;it!=buf.cend() && isdigit(*it); ++it) {
		    num=num*10 + *it-'0';
		}
		--it;
		--num;
		auto list_it = lookup.begin();
		while(num--) ++list_it;
		std::string s = *list_it;
		lookup.erase(list_it);
		lookup.push_front(s);
		printf("%s", s.c_str());
	    } else {
	       putchar(c);
	    }
	}
    }
}
