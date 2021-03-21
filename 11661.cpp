#include <algorithm>
#include <cstdio>
#include <limits>


int l, min_distance, last;
char line[2000001];

int main() {
    while(scanf("%d", &l)!=EOF) {
        if(l==0) break;

        min_distance = std::numeric_limits<int>::max();
	last = 0;

	scanf("%s", &line);
        for(int i=0; line[i]!=0; ++i) {
	    char c = line[i];
 
	    if(c=='Z') {
	        min_distance = 0;
	        break;
	    }
	    if(c!='.') {
	        if(line[last]!='.' && c!=line[last]) {
		    min_distance = std::min(min_distance, i-last);
		}
		last = i;
	    }
	}
	printf("%d\n", min_distance);
    }
}
