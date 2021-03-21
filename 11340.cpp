#include<stdio.h>
#include<string.h>

int i, n, k, total, c, v, m;
int table[258];
char line[10001];

int main() {
  scanf("%d\n", &n);
  while(n-- && scanf("%d\n", &k)==1) {
    total = 0;
    memset(table, 0, sizeof table);
    while(k-- && scanf("%c %d\n", &c, &v)==2) table[c+128] = v;
    scanf("%d\n", &m);
    while(m-- && gets(line)!=NULL) {
      for(i=0; line[i]; ++i) total += table[line[i]+128];
    }
    printf("%d.%02d$\n", total/100, total%100);
  }
}
