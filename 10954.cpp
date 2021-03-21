#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

int n, cost, i;

int main() {
    while(scanf("%d", &n)!=EOF && n!=0) {
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        while(n--) {
            scanf("%d", &i);
	    q.push(i);
        }
	cost = 0;
	while(q.size() > 1) {
	    int a = q.top(); q.pop();
	    int b=  q.top(); q.pop();
	    int s = a + b;
	    cost += s;
	    q.push(s);
	}
	printf("%d\n", cost);
    }
}
