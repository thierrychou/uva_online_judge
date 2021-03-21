#include <cstdio>
#include <cstring>
#include <set>

int r, stroke, i;
char s[10000], g[10000];
bool guessed[26];

int main() {
    while(scanf("%d", &r)!=EOF && r!=-1) {
	printf("Round %d\n", r);
        scanf("%s %s", &s, &g);
	
	std::set<char> flags;
	stroke = 0;
	memset(guessed, false, sizeof(guessed));
	for(i=0; s[i]!='\0'; ++i) {
	    flags.insert(s[i]);
	}
	for(i=0; g[i]!='\0'; ++i) {
	    char c = g[i]-'a';
	    if(!guessed[c]) {
	        if(flags.erase(g[i])==0) {
	            ++stroke;
		    if(stroke==7) break;
		} else if(flags.empty()) {
		    break;
		}
		guessed[c] = true;
	    }
	}
	if(stroke==7) {
	    printf("You lose.\n");
	} else if(flags.empty()) {
	    printf("You win.\n");
	} else {
	    printf("You chickened out.\n");
	}
    }
}
