#include<stdio.h>
#include<string.h>
#include<cfloat>

int i,n,p, met, maxMet, testcase=1;
float price, minPrice;
char result[81], buffer[81];

int main() {
  while(scanf("%d %d", &n, &p) != EOF) {
    if(n==0 && p==0) return 0;

    maxMet = 0;
    minPrice = DBL_MAX;

    getchar();
    for(;n>0;--n) gets(buffer);

    for(;p>0;--p) {
      gets(buffer);
      scanf("%f %d", &price, &met);
      getchar();
      if(met>maxMet) {
        maxMet = met;
        minPrice = price;
        strcpy(result, buffer);
      } else if(met==maxMet && price<minPrice) {
        minPrice = price;
        strcpy(result, buffer);
      }
      for(;met>0;--met) gets(buffer);
    }
    if(testcase!=1) printf("\n");
    printf("RFP #%d\n%s\n", testcase++, result);
    
  }
}
