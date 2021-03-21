#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

int r;
char rule_find[11][81];
char rule_replace[11][81];

int main() {
    while(scanf("%d", &r)!=EOF) {
	if(r==0) break;
	getchar();
        for(int i=0; i<r; ++i) {
            gets(rule_find[i]);
    	    gets(rule_replace[i]);
        }
        std::string text;
        getline(std::cin, text);
        for(int i=0; i<r; ++i) {
	    size_t pos;
	    size_t len = strlen(rule_find[i]);
   	    while((pos = text.find(rule_find[i])) != std::string::npos) {
	        text.replace(pos, len, rule_replace[i]);
	    }
        }
        printf("%s\n", text.c_str());
    }
}
