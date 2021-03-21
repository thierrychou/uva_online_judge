#include <cstdio>
#include <map>
#include <string>

int tc;
char line[15];
std::map<std::string, std::string>::const_iterator it;

int main() {
    tc = 0;
    std::map<std::string, std::string> m;
    m["HELLO"] = "ENGLISH";
    m["HOLA"] = "SPANISH";
    m["HALLO"] = "GERMAN";
    m["BONJOUR"] = "FRENCH";
    m["CIAO"] = "ITALIAN";
    m["ZDRAVSTVUJTE"] = "RUSSIAN";
    while(scanf("%s", &line)!=EOF && line[0]!='#') {
	it = m.find(line);
	if(it==m.end()) {
	    printf("Case %d: UNKNOWN\n", ++tc);
	} else {
	    printf("Case %d: %s\n", ++tc, it->second.c_str());
	}
    }
}
