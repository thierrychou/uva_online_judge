#include<stdio.h>
#include<stack>

bool correct;
int i,n;
char c, line[129];

int main() {
  scanf("%d",&n);
  getchar();
  for(;n>0;n--) {
    gets(line);
    correct = true;
    std::stack<char> s;
    for(i=0; line[i]; ++i) {
      c = line[i];
      if(c!='(' && c!=')' && c!='[' && c!=']') continue;
      if(c=='(' || c=='[') s.push(c);
      else if(c== ')' && !s.empty() && s.top()=='(') s.pop();
      else if(c== ']' && !s.empty() && s.top()=='[') s.pop();
      else {
	correct = false;
	break;
      }
    }
    if(correct && s.empty()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
