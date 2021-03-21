#include <cstdio>
#include <map>
#include <string>

char line[100];
char english[11], foreign[11];

int main() {
    std::map<std::string, std::string> m;
    while(gets(line)!=NULL) {
        if(line[0]=='\0') break;
	sscanf(line, "%s %s", english, foreign);
	m[std::string(foreign)] = std::string(english);
    }
    while(gets(line)!=NULL) {
        std::map<std::string, std::string>::const_iterator it = m.find(std::string(line));
	if(it == m.end()) {
	    printf("eh\n");
	} else {
	    printf("%s\n", it->second.c_str());
	}
    }
}
