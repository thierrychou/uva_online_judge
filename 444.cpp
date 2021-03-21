#include<algorithm>
#include<cctype>
#include<cstdio>
#include<cstring>

int size, i, n, ptr;
char line[1000], output[3001];

int main() {
  while(gets(line)!=NULL) {
    size = strlen(line);
    memset(output, 0, sizeof(output));

    ptr=0;
    if(isdigit(line[0])) {
      //decode
      i=size-1;
      while(i>0) {
        if(line[i]-'0'<3) {
	  n = (line[i-2]-'0') + (line[i-1]-'0')*10 + (line[i]-'0')*100;
	  i -= 3;
	} else {
          n = (line[i-1]-'0') + (line[i]-'0')*10;
	  i -= 2;
	}
	output[ptr++] = n;
      }
      output[ptr] = 0;
    } else {
      //encode
      for(i=0; i<size; ++i) {
        ptr+=sprintf(output+ptr, "%d", line[i]);
      }
      std::reverse(output, output+ptr);
    }
    printf("%s\n", output);
  }
}
