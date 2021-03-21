#include <cstdio>
#include <set>

int k, m,i,t,c,r,available;
bool degree;

int main() {
    while(scanf("%d", &k) !=EOF && k!=0) { 
        scanf("%d", &m);
        std::set<int> taken;
        for(i=0; i<k; ++i) {
            scanf("%d", &t);
            taken.insert(t);
        }
        degree = true;
        while(m--) {
           scanf("%d %d", &c, &r);
             while(c--) {
                scanf("%d", &available);
                if(degree && taken.find(available)!=taken.end()) {
                    --r;
                }
            }
            if(r>0) degree = false;
        }
        printf(degree ? "yes\n" : "no\n");
    }
}
