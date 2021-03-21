#include <cstdio>
#include <map>
#include <string>

inline void gen(std::map<std::string, int>& dict) {
    int count = 1;
    char s[6];
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++) {
        s[1] = '\0';
	dict[std::string(s)] = count++;
    }
    for (s[0] = 'a'; s[0] <= 'z' - 1; s[0]++)
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++) {
	s[2] = '\0';
	dict[std::string(s)] = count++;
    }
    for (s[0] = 'a'; s[0] <= 'z' - 2; s[0]++)
	for (s[1] = s[0] + 1; s[1] <= 'z' - 1; s[1]++)
	    for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++) {
	        s[3] = '\0';
		dict[std::string(s)] = count++;
	    }

    for (s[0] = 'a'; s[0] <= 'z' - 3; s[0]++)
	for (s[1] = s[0] + 1; s[1] <= 'z' - 2; s[1]++)
	    for (s[2] = s[1] + 1; s[2] <= 'z' - 1; s[2]++)
		for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++) {
		    s[4] = '\0';
		    dict[std::string(s)] = count++;
		}

    for (s[0] = 'a'; s[0] <= 'z' - 4; s[0]++)
	for (s[1] = s[0] + 1; s[1] <= 'z' - 3; s[1]++)
	    for (s[2] = s[1] + 1; s[2] <= 'z' - 2; s[2]++)
		for (s[3] = s[2] + 1; s[3] <= 'z' - 1; s[3]++)
		    for (s[4] = s[3] + 1; s[4] <= 'z'; s[4]++) {
			s[5] = '\0';
			dict[std::string(s)] = count++;
		    }
}

char line[6];

int main() {
    std::map<std::string, int> dictionary;
    gen(dictionary);
    while(gets(line)!=NULL) {
        std::map<std::string, int>::const_iterator it = dictionary.find(std::string(line));
	if(it==dictionary.end()) {
	    printf("0\n");
	} else {
	    printf("%d\n", it->second);
	}
    }
}
