#include <cstdio>
#include <cstring>

inline bool isVowel(char c) {
    return c=='a' || c=='e'||c=='i'||c=='o'||c=='u';
}

inline bool isSame(const char* n1, const char* n2) {
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    if(l1==l2) {
        for(int i=0; i<l1; ++i) {
	    char c1 = n1[i];
	    char c2 = n2[i];
	    if(c1==c2 || (isVowel(c1)&&isVowel(c2))) {
	        continue;
	    } else {
	        return false;
	    }
	}
	return true;
    } else {
	return false;
    }
}

int n;
char name1[21], name2[21];

int main() {
    scanf("%d", &n);
    while(n--) {
	scanf("%s", &name1);
	scanf("%s", &name2);
	printf(isSame(name1,name2) ? "Yes\n" : "No\n");
    }
}
