#include<cstdio>
#include<map>

int i, result_ptr;
char code, last_code, line[21], result[21];
const char* words  = "BFPVCGJKQSXZDTLMNR";
const char* digits = "111122222222334556";

int main() {
  std::map<char, char> codes;
  for(i=0; words[i]!='\0'; ++i)
    codes[words[i]] = digits[i];

  while(gets(line)!=NULL) {
    result_ptr = 0;
    last_code = '!';
    for(i=0; line[i]!='\0'; ++i) {
      code = codes[line[i]];
      if(code != 0 && code != last_code) {
        result[result_ptr++] = code;
      }
      last_code = code;
    }
    result[result_ptr] = '\0';
    printf("%s\n", result);
  }
}
