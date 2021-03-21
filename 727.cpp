#include<cctype>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>

#define LINE_SIZE 5000

bool first_case;
int i,n, ptr;
char c, op, line[LINE_SIZE], postfix[100];

int main() {
  first_case = true;
  std::map<char, int> order;
  order['*'] = 3;
  order['/'] = 3;
  order['+'] = 4;
  order['-'] = 4;
  order['('] = 5;
  order[')'] = 5;

  scanf("%d\n\n", &n);
  for(i=0; i<n; ++i) {
    std::stack<char> s;
    memset(postfix, 0, sizeof(postfix));
    ptr=0;

    while(fgets(line, LINE_SIZE, stdin)!=NULL && line[0]!='\n') {
      c = line[0];

      if(isdigit(c)) postfix[ptr++] = c;
      else if(s.empty() || c=='(') s.push(c);
      else if(c == ')') {
	while(!s.empty() && s.top() != '(') {
	  postfix[ptr++] = s.top();
	  s.pop();
	}
	s.pop();
      } else if(order[c] < order[s.top()]) s.push(c);
      else {
	do {
	  postfix[ptr++] = s.top();
	  s.pop();
	} while(!s.empty() && order[c] >= order[s.top()]);
	s.push(c);
      }
    }
    while(!s.empty()) {
      postfix[ptr++] = s.top();
      s.pop();
    }
    if(first_case) {
      printf("%s\n", postfix);
      first_case = false;
    } else
      printf("\n%s\n", postfix);
  }
}
