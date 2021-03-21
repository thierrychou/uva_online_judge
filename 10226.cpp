#include<cstdio>
#include<map>
#include<string>

char line[310];
int  test_case, total;
std::map<std::string,int>::const_iterator it;

int main() {
  std::map<std::string, int> trees;

  scanf("%d\n\n", &test_case);
  while(test_case--) {
    total = 0;
    trees.clear();
    
    while(gets(line)!=NULL && line[0] != '\0') {
      trees[std::string(line)]++;
      ++total;
    }

    for(it=trees.begin(); it!=trees.end(); ++it) {
      printf("%s %.4f\n", it->first.c_str(), it->second*100.0 / total);
    }
    if(test_case) putchar('\n');
  }
}
