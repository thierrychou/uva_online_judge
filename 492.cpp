#include<cstdio>
#include<cstring>
#include<cctype>

int i, ptr;
char word[10000000], line[10000000];

inline bool isvowel(char c) {
  c = tolower(c);
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

inline void decode(const char* word) {
  if(isvowel(word[0]))
    printf("%say", word);
  else	  
    printf("%s%cay", word+1, word[0]);
}

int main() {
  while(gets(line)!=NULL) {
    for(i=0, ptr=0; line[i]!=0; ++i) {
      char c = line[i];
      if(isalpha(c)) {
        word[ptr++] = c;
      } else {
	if(ptr!=0) {
	  word[ptr]=0;
	  decode(word);
	  ptr = 0;
	}
	putchar(c);
      }
    }
    if(ptr!=0) {
      word[ptr]=0;
      decode(word);
    }
    printf("\n");
  }
}
