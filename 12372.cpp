#include <cstdio>

int tc,t,l,w,h;

int main() {
    tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &l, &w, &h);
        if(l<=20 && w<=20 && h<=20) {
            printf("Case %d: good\n", ++tc);
        } else {
            printf("Case %d: bad\n", ++tc);
        }
    }
}
