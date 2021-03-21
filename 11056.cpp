#include <algorithm>
#include <cstdio>
#include <cctype>
#include <set>
#include <string>

int n, count;
int min, sec, ms;
char name[21];

class record {
public:
    std::string name;
    int min, sec, ms;
};

inline bool compare_names(std::string a, std::string b) {
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);

    return a < b;
}

struct comp {
    bool operator() (const record& a, const record& b) const {
        if (a.min == b.min) {
            if (a.sec == b.sec) {
                if (a.ms == b.ms) {
                    return compare_names(a.name, b.name);
                } else {
                   return a.ms < b.ms;
		}
            } else {
                return a.sec < b.sec;
	    }
        } else {
	    return a.min < b.min;
	}
    }
};

int main() {
    while(scanf("%d", &n)!=EOF) {
	std::set<record, comp> s;
	while(n--) {
            scanf("%s : %d min %d sec %d ms", &name, &min, &sec, &ms);
	    record r;
	    r.name = std::string(name);
	    r.min = min;
	    r.sec = sec;
	    r.ms = ms;
	    s.insert(r);
	}
	count = 0;
	for(std::set<record, comp>::iterator it=s.begin(); it!=s.end(); it++) {
	    if(count%2==0) {
		printf("Row %d\n", count/2+1);
	    }
	    count++;
	    printf("%s\n", it->name.c_str());
	}
	printf("\n");
    }
}
