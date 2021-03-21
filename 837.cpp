#include <algorithm>
#include <cstdio>
#include <map>

int cases, nl;
double x1, y1, x2, y2, r;

int main() {
    scanf("%d", &cases);
    bool first_case = true;
    while(cases--) {
	if(first_case) {
	    first_case = false;
	} else {
	    printf("\n");
	}
        scanf("%d", &nl);
	std::map<double, double> m;
        while(nl--) {
            scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r);
	    double x_start = std::min(x1, x2);
	    double x_end = std::max(x1, x2);
	    m[x_start] = r;
	    m[x_end] = 1.0 / r;
	}
	printf("%d\n", m.size()+1);
	std::map<double, double>::const_iterator it = m.begin();
	printf("-inf %.3f 1.000\n", it->first);
	double last_x = it-> first;
	double percentage = it->second;
	++it;
	while(it != m.end()) {
	    printf("%.3f %.3f %.3f\n", last_x, it->first, percentage);
	    last_x = it->first;
	    percentage *= it->second;
	    ++it;
	}
	printf("%.3f +inf 1.000\n", last_x);
    }
}
