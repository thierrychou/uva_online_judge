#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

const static std::string phrase = "the quick brown fox jumps over the lazy dog";
int mapping[26];

inline bool is_key_sentence(const std::string& s) {
    if(s.length() != phrase.length()) return false;
  
    memset(mapping, 0, sizeof(mapping));

    for(int i=0; i<s.length(); ++i) {
	if(phrase[i]==' ') {
	    if(s[i]==' ') continue;
	    return false;
	}

	int encode=s[i]-'a';
	if(mapping[encode]==0) {
	    mapping[encode]=phrase[i];
	} else {
	    if(mapping[encode] != phrase[i]) return false;
	}
    }
    return true;
}

int main() {
    bool first = true;
    int tc;
    std::string line;
   
    scanf("%d\n", &tc);
    while(tc--) {
	std::vector<std::string> inputs;
	bool found = false;

	while(std::getline(std::cin, line)) {
	    size_t l = line.length();
	    if(l==0) break;
	    found = found || is_key_sentence(line);
	    inputs.push_back(line);
	}
	if(found) {
	    for(int i=0; i<inputs.size(); ++i) {
	        const std::string& s = inputs[i];
	        for(int x=0; x<s.length(); ++x) {
		    printf("%c", (s[x]==' ') ? ' ' : mapping[s[x]-'a']);
	        }
	        printf("\n");
	    }
	} else {
	    printf("No solution.\n");
	}
	if(tc!=0) {
	    printf("\n");
	}
    }
}
