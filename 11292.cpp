#include <cstdio>
#include <set>

int i, n, m, t, d[20001];

int main() {
    while(scanf("%d %d", &n, &m) !=EOF) {
        if(n==0 && m==0) {
            break;
	} else {
	    std::multiset<int> k;
	    for(i=0; i<n; ++i) scanf("%d", &d[i]);
	    for(i=0; i<m; ++i) {
	        scanf("%d", &t);
		k.insert(t);
	    }

	    bool result = true;
	    int cost = 0;
	    for(i=0; i<n; ++i) {
	        std::multiset<int>::iterator it = k.lower_bound(d[i]);
	        if(it == k.end()) {
		    result = false;
		    break;
	        } else {
		    cost += *it;
		    k.erase(it);
		}
	    }
	    if(result) {
		printf("%d\n", cost);
	    } else {
	        printf("Loowater is doomed!\n");
	    }
	}
    } 
}

