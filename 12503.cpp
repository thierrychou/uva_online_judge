#include <cstdio>
#include <vector>

char line[50];
int shift, t, n, p, i;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
	p = 0;
	std::vector<int> v;
	while(n--) {
	    scanf("%s", &line);
	    if(line[0] == 'L')      shift = -1;
	    else if(line[0] == 'R') shift = 1;
	    else {
	        scanf(" AS %d", &i);
		shift = v[i-1];
	    }
	    v.push_back(shift);
	    p += shift;
	}
	printf("%d\n", p);
    }
}
