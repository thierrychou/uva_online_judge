#include <cstdio>
#include <climits>
#include <vector>

long long count;
long v[100001], i, n;

inline void merge(long l, long m, long r) {
    std::vector<long> left;
    std::vector<long> right;

    for(i=l; i<=m; ++i) left.push_back(v[i]);
    for(i=m+1; i<=r; ++i) right.push_back(v[i]);

    left.push_back(LONG_MAX);
    right.push_back(LONG_MAX);

    size_t i_l = 0;
    size_t i_r = 0;
    for(i=l; i<=r; ++i) {
        if(left[i_l] <= right[i_r]) {
	    v[i] = left[i_l++];
	} else {
	    v[i] = right[i_r++];
	    count += m - l + 1 - i_l;
	}
    }
}

void merge_sort(long l, long r) {
    if(l<r) {
        long mid = (l+r)/2;
	merge_sort(l, mid);
	merge_sort(mid+1, r);
	merge(l, mid, r);
    }
}

int main() {
    while(scanf("%ld", &n)!=EOF && n!=0) {
        for(i=0; i<n; ++i) scanf("%lld", &v[i]);
	count = 0;
	merge_sort(0, n-1);
	if(count%2) {
	    printf("Marcelo\n");
	} else {
	    printf("Carlos\n");
	}
    }
}
