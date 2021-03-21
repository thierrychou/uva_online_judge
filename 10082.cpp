
#include <stdio.h>
#include <map>
#include <string.h>


const char wrg[] = "2WSX3EDC4RFV5TGB6YHN7UJM8IK,9OL.0P;/-['=]\\";
const char org[] = "1QAZ2WSX3EDC4RFV5TGB6YHN7UJM8IK,9OL.0P;-[]";

char line[500];
int i, len;
std::map<char, char> keymap;

int main(){
  for(i=0; i<42; ++i){
    keymap[wrg[i]] = org[i];
  }

  while(gets(line) != NULL){
    len = strlen(line);
    
    for(i=0; i<len; ++i){
      if(line[i] == ' '){
        printf(" ");
      }else{
        printf("%c", keymap[line[i]]);
      }
    }
    printf("\n");
  }
}
