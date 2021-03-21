#include <cstdio>
#include <map>
#include <string>

inline char keypad(const char& a) {
    if(isdigit(a)) return a;
    switch(a) {
    case 'A': case 'B': case 'C':
        return '2';
    case 'D': case 'E': case 'F':
	return '3';
    case 'G': case 'H': case 'I':
        return '4';
    case 'J': case 'K': case 'L':
	return '5';
    case 'M': case 'N': case 'O':
	return '6';
    case 'P': case 'R': case 'S':
	return '7';
    case 'T': case 'U': case 'V':
	return '8';
    case 'W': case 'X': case 'Y':
        return '9';
    default:
	return ' ';
    }
}

bool first, noDup;
int datasets, n, pos, i;
char c;
char standard[9], line[10000];
std::map<std::string, int>::const_iterator it;

int main() {
    first = true;
    scanf("%d", &datasets);
    while(datasets--) {
	if(!first) printf("\n");

	std::map<std::string, int> m;
        scanf("%d", &n);
	while(n--) {
	    scanf("%s", line);
	    
	    pos = 0;
	    for(i=0; line[i]!='\0'; ++i) {
	        c = keypad(line[i]);
		if(c!=' ') {
		    standard[pos++] = c;
		}
		if(pos==3) standard[pos++] = '-';
	    }
	    standard[pos]='\0';
	    m[std::string(standard)]++;
	}
	noDup = true;
        for(it=m.begin(); it!=m.end(); ++it) {
            if(it->second>1) {
	        printf("%s %d\n", it->first.c_str(), it->second);
	        noDup = false;
	    }
	}
	if(noDup) {
	    printf("No duplicates.\n");
	}
        first = false;
    }
}
