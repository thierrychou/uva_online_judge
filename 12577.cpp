#include <cstdio>

char line[6];

int main() {
    int c = 0;
    while(gets(line)!=NULL && line[0]!='*') {
        if(line[0]=='H') printf("Case %d: Hajj-e-Akbar\n", ++c);
	else printf("Case %d: Hajj-e-Asghar\n", ++c);
    }
}
