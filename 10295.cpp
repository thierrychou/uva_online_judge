#include <cstdio>
#include <map>
#include <string>

int m,n,v;
unsigned long int pts;
char k[100], w[100];
std::map<std::string, int>::iterator it;

int main() {
    std::map<std::string, int> d;
    scanf("%d %d", &m, &n);
    while(m--) {
        scanf("%s %d", &k, &v);
	d[std::string(k)] = v;
    }
    while(n--) {
        pts = 0;
	while(scanf("%s", &w)!=EOF && w[0]!='.') {
	    it = d.find(std::string(w));
	    if(it != d.end()){
	        pts += it->second;
	    }
	}
	printf("%ld\n", pts);
    }
}
