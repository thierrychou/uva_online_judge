#include <algorithm>
#include <climits>
#include <cstdio>
#include <map>

int n, pizza, i;
char line[601];

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%s", &line);

	std::map<char,int> m;
	for(i=0; line[i]!=0; ++i) {
	    m[line[i]]++;
	}
	pizza = INT_MAX;
	pizza = std::min(pizza, m['M']);
	pizza = std::min(pizza, m['A']/3);
	pizza = std::min(pizza, m['R']/2);
	pizza = std::min(pizza, m['G']);
	pizza = std::min(pizza, m['I']);
	pizza = std::min(pizza, m['T']);
	printf("%d\n", pizza);
    }
}
