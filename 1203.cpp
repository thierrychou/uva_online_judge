#include <cstdio>
#include <queue>

class query {
public:
    int num;
    int period;
    int next_period;

    inline bool operator < (const query& q) const {
        if(this->next_period == q.next_period) {
	    return this->num > q.num;
	}
        return this->next_period > q.next_period;
    }
};

int n, p, k;
char line[100];

int main() {
    std::priority_queue<query> q;
    while(gets(line)!=NULL && line[0] != '#') {
        sscanf(line, "Register %d %d", &n, &p);
	query reg;
	reg.num = n;
	reg.period = reg.next_period = p;
	q.push(reg);
    }
    scanf("%d", &k);
    while(k--) {
        query req = q.top();
	q.pop();
	printf("%d\n", req.num);
	req.next_period += req.period;
	q.push(req);
    }
}
