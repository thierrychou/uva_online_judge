#include <cstdio>
#include <map>
#include <vector>

int n;

int main() {
    std::map<int, int> m;
    std::vector<int>   l;
    while(scanf("%d", &n)!=EOF) {
        std::map<int, int>::iterator it = m.find(n);
        if(it == m.end()) {
	    m[n] = 1;
	    l.push_back(n);
	} else {
	    it->second++;
	}	
    }
    for(std::vector<int>::const_iterator it = l.begin(); it!=l.end(); ++it) {
        printf("%d %d\n", *it, m[*it]);
    }
}
