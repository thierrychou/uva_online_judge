#include <cstdio>
#include <map>
#include <string>

int tc,ptr;
char codes[10], line[2001];

char symbol[53]={ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                   'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                '4', '5', '6', '7', '8', '9', ',', '.', '?', '\'',
                '!', '/', '(', ')', '&', ':', ';', '=', '+', '-',
                '_', '\"', '@' };
char code[53][10]= { ".-",     "-...",   "-.-.",  "-..",    ".",     "..-.",   "--.",    "....",   "..",     ".---",
                    "-.-",    ".-..",   "--",    "-.",     "---",   ".--.",   "--.-",   ".-.",    "...",    "-",
                 "..-",    "...-",   ".--",   "-..-",   "-.--",  "--..",   "-----",  ".----",  "..---",  "...--",
                 "....-",  ".....",  "-....", "--...",  "---..", "----.",  "--..--", ".-.-.-", "..--..", ".----.",
                 "-.-.--", "-..-.",  "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-",  ".-.-.",  "-....-",
                 "..--.-", ".-..-.", ".--.-." };


int main() {
    std::map<std::string, char> mapping;

    for(int i=0; i<53; ++i) {
        mapping[code[i]]=symbol[i];
    }
    scanf("%d\n", &tc);
    for(int t=1; t<=tc; ++t) {
	if(t!=1) printf("\n");
	printf("Message #%d\n", t);

	ptr=0;
        gets(line);
	for(int i=0; line[i]!=0; ++i) {
	    char c = line[i];
	    if(c==' ') {
	        if(ptr>0) {
		    codes[ptr]=0;
		    putchar(mapping[codes]);
		    ptr=0;
		} else {
		    putchar(' ');
		}
	    } else {
	        codes[ptr++] = c;
	    }
	}
	if(ptr>0) {
	    codes[ptr]=0;
	    putchar(mapping[codes]);
	}
	putchar('\n');
    }
}
