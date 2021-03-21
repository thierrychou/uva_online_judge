#include <cstdio>
#include <cctype>
#include <set>
#include <string>

int i, j;
char c, word[201], line[201];

int main() {
    std::set<std::string> d;
    while(gets(line)!=NULL) {
	j = 0;
        for(i=0; line[i]!='\0'; ++i) {
	    c = tolower(line[i]);
	    if(c>='a' && c<='z') {
	        word[j++] = c;
	    } else if(j>0) {
	        word[j] = '\0';
		d.insert(std::string(word));

		// reset
		j=0;
	    }
	}
	if(j>0) {
	    word[j] = '\0';
	    d.insert(std::string(word));
	}
    }
    for(std::set<std::string>::const_iterator it = d.begin(); it!=d.end(); ++it) {
        printf("%s\n", it->c_str());
    }
}
