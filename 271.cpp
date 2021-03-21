#include <cstdio>
#include <cstring>

char line[300];

int main() {
    while(gets(line)!=NULL) {
	int count = 0;
        int size = strlen(line);
	for(int i = size-1; i>=0; --i) {
	    char c = line[i];
	    if('p'<=c && c<='z') {
	        ++count;
	    } else if(c=='N') {
		if(count==0) {
		    break;
		}
	    } else if(c=='C'||c=='D'||c=='E'||c=='I') {
		if(count<2) {
		    count=0;
		    break;
		} else {
		    count--;
		}
	    } else {
	        count=0;
		break;
	    }
	    
	}
	printf( count==1 ? "YES\n" : "NO\n");
    }
}
