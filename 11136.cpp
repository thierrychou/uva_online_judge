#include <cstdio>
#include <set>

int n, k;
unsigned int amount;

int main() {
    while(scanf("%d", &n)!=EOF) {
	if(n==0) break;

	std::multiset<unsigned int> urn;
	unsigned long int cost = 0;
	while(n--) {
	    scanf("%d", &k);
	    while(k--) {
		scanf("%u", &amount);
		urn.insert(amount);
	    }

	    std::multiset<unsigned int>::reverse_iterator it_max = urn.rbegin();
	    std::multiset<unsigned int>::iterator it_min = urn.begin();
	    cost += *it_max - *it_min;
	    urn.erase(--it_max.base());
	    urn.erase(it_min);
	}
	printf("%lu\n", cost);
    }
}
