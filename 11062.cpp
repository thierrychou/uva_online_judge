#include <cctype>
#include <string>
#include <cstdio>
#include <set>

char line[100001];
bool hyphenated;

int main() {
    std::set<std::string> dictionary;
    std::string word;
    while(gets(line)!=NULL) {
	hyphenated = false;
        for(int i=0; line[i]!=0; ++i) {
            if(isalpha(line[i])) {
	        word.push_back(tolower(line[i]));
	    } else if(line[i] == '-') {
		if(line[i+1]==0) {
		    hyphenated=true;
		    continue;
		} else {
		    word.push_back('-');
	 	}
	    } else {
		// all other chars.
		if(!word.empty()) {
		    dictionary.insert(word);
		    word.clear();
		}
	    }
	}
	if(!hyphenated && !word.empty()) {
	    dictionary.insert(word);
	    word.clear();
	}
    }
    for(std::set<std::string>::iterator it=dictionary.begin(); it!=dictionary.end(); ++it) {
        printf("%s\n", it->c_str());
    }
}
