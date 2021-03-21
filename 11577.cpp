#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

char line[201];
int letters[27];
int tc, i, max_value;

int main() {
    scanf("%d", &tc);
    getchar();
    while(tc--) {
        gets(line);
	
	memset(letters, 0, sizeof(letters));
	max_value=0;
	
	for(i=0; line[i]!=0; ++i) {
	    char c = line[i];
	    if(isalpha(c)) {
		char v = tolower(c) - 'a';
	        letters[v]++;
		max_value = std::max(max_value, letters[v]);
	    }
	}
	for(i=0; i<26; ++i) {
	    if(letters[i]==max_value) {
	        printf("%c", i + 'a');
	    }
	}
	printf("\n");
    }
}
