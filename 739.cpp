#include<stdio.h>
#include<cstring>

int codes[] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
int i, digit, code, last, result[3];
char name[21];

int main() {
  printf("         NAME                     SOUNDEX CODE\n");
  while(scanf("%s", name)!=EOF) {
    printf("         %-25s%c", name, name[0]);
    memset(result, 0, sizeof(result));
    digit=0;
    last = codes[name[0]-'A'];
    i = 1;
    do {
      code = codes[name[i]-'A'];
      if(code!=last && code!=0) {
        result[digit++] = code;
      }
      last = code;
    } while(name[++i]!='\0' && digit<3);
    printf("%d%d%d\n", result[0], result[1], result[2]);
  }
  printf("                   END OF OUTPUT\n");
}
