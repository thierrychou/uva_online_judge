#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <string>

int size, number, diff, first, second;
char input[20];

int main() {
    std::set<int> chain;
    while(gets(input)!=NULL && !(strlen(input)==1 && input[0]=='0')) {
	number = atoi(input);
	
	chain.insert(number);
	sprintf(input, "%d", number);
	
	printf("Original number was %d\n", number);

	while(chain.size()<=1000) {
	    sprintf(input, "%d", number);
	    size = strlen(input);
            std::sort(input, input+size);
    	    std::string asc(input);
	    std::reverse(input, input+size);
	    std::string dsc(input);

	    first = atoi(dsc.c_str());
	    second = atoi(asc.c_str());
	    diff = first - second;
	    printf("%d - %d = %d\n", first, second, diff);
	    if(chain.find(diff)==chain.end()) {
	        chain.insert(diff);
	    } else {
	        printf("Chain length %d\n\n", chain.size());
		break;
 	    }
	    number = diff;
        }
	chain.clear();
    }
}

