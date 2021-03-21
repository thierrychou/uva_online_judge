#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <iostream>
#include <vector>

inline bool is_oneoff(const std::string& a, const std::string& b) {
    int diff = 0;
    const std::string& shorter = (a.size() > b.size() ? b : a);
    const std::string& longer = (a.size() > b.size() ? a : b);

    for (int i = 0, j = 0; i < longer.size() && j < shorter.size(); ) {
        if(longer[i] == shorter[j]) {
            i++; j++;
        } else {
            diff++;
            i++;

            if (diff > 1) return false;
        }
    }

    return true;
}

inline void find_diff(const std::string& a, const std::string& b, std::vector<int>& pos) {
    for(int i=0; i<a.size(); ++i) {
	if(a[i] != b[i]) {
	    pos.push_back(i);
	    if(pos.size() > 2) return;
	}
    }
}

inline void correction(const std::string& word, const std::vector<std::string>& dictionary, const std::set<std::string>& lookup) {
    if(lookup.find(word) != lookup.end()) {
	printf("%s is correct\n", word.c_str());
	return;
    }

    bool found = false;
    for(std::vector<std::string>::const_iterator it=dictionary.begin(); it!=dictionary.end(); it++) {
        if(abs(word.size() - it->size()) > 1) continue;
	if(word.size() == it->size()) {
            std::vector<int> pos;
	    find_diff(word, *it, pos);
	    if(pos.size()==1) {
	        printf("%s is a misspelling of %s\n", word.c_str(), it->c_str());
		found = true;
		break;
	    } else if(pos.size()==2) {
		if(pos[0]+1 == pos[1] &&
		    word[pos[0]] == (*it)[pos[1]] && word[pos[1]] == (*it)[pos[0]]) {
	            printf("%s is a misspelling of %s\n", word.c_str(), it->c_str());
		    found = true;
	            break;
		}
		   
	    }
	} else {
	    if(is_oneoff(word, *it)) {
                printf("%s is a misspelling of %s\n", word.c_str(), it->c_str());
	        found = true;
	        break;
	    }
	}
    }
    if(!found) {
	printf("%s is unknown\n", word.c_str());
    }
}


int n, q;

int main() {
    std::string word;
    std::set<std::string> lookup;
    std::vector<std::string> dictionary;
    std::cin >> n;
    while(n--) {
        std::cin >> word;
	dictionary.push_back(word);
	lookup.insert(word);
    }
    std::cin >> q;
    while(q--) {
	std::cin >> word;
	correction(word, dictionary, lookup);
    }
}
