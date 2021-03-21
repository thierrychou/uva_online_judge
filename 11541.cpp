#include <cstdio>
#include <cctype>

int t, i, o, letter_index, code;
char line[5000], output[201];

int main() {
    scanf("%d", &t);
    for(int c=1; c<=t; ++c) {
        scanf("%s", &line);

	o=0;
	for(i=0;line[i] != 0; ++i) {
	    letter_index = i;
	    code = 0;
            while(line[i+1]!=0 && isdigit(line[i+1])) {
		i++;
		code = code*10 + (line[i]-'0');
	    }
	    for(int j=0; j<code; ++j) output[o++] = line[letter_index];
	}
	output[o] = 0;
	printf("Case %d: %s\n", c, output);
    }
}
