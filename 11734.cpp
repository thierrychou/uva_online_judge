#include <cstdio>
#include <cstring>

int testcases;
char output1[21], output2[21], space_removed_output[21];

const char* remove_space(const char* str) {
    int ptr = 0;
    for(int i=0; str[i]!=0; ++i) {
        if(str[i]!=' ') {
	    space_removed_output[ptr++] = str[i];
	}
    }
    space_removed_output[ptr]=0;
    return space_removed_output;
}

int main() {
    scanf("%d\n", &testcases);
    for(int t=1; t<=testcases; ++t) {
	gets(output1);
	gets(output2);
	if(strcmp(output1, output2)==0) {
	    printf("Case %d: Yes\n", t);
	} else if (strcmp(remove_space(output1), output2)==0) {
	    printf("Case %d: Output Format Error\n", t);
	} else {
	    printf("Case %d: Wrong Answer\n", t);
	}
    }
}
