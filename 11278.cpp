#include <cstdio>
#include <map>
#include <string>

char line[1001];

std::string input  = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
std::string output = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";


int main() {
    std::map<char, char> mapping;
    for(int i=input.size()-1; i>=0; --i) mapping[input[i]] = output[i];
    while(gets(line)!=NULL) {
        for(int i=0; line[i]!=0; ++i) {
	    putchar(mapping[line[i]]);
	}
	putchar('\n');
    }
}
