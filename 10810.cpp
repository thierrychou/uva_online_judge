#include <cstdio>
#include <vector>

unsigned long long count;
int a[500001];
int i,n;

inline void merge(int l, int m, int r) {
  std::vector<int> left;
  std::vector<int> right;

  for(i=l; i <= m; ++i) left.push_back(a[i]);
  for(i=m+1; i <=r; ++i) right.push_back(a[i]);

  left.push_back(999999999+1);
  right.push_back(999999999+1);

  size_t i_l=0;
  size_t i_r=0;
  for(i=l; i<=r; ++i) {
    if(left[i_l] <= right[i_r]) {
        a[i] = left[i_l++];
    } else {
	a[i] = right[i_r++];
	count += m - l + 1 - i_l;
    }
  }
}

void mergeSort(int l, int r) {
    if(l<r) {
        int mid = (l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	merge(l,mid,r);
    }
}

int main() {
    while(scanf("%d", &n) != EOF && n!=0) {
        for(i=0; i<n; ++i) scanf("%d", &a[i]);

	count = 0;
        mergeSort(0, n-1);
	printf("%ld\n", count);
    }
}
