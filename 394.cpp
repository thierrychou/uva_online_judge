#include<stdio.h>
#include<string>
#include<map>
#include<vector>
using namespace std;

int i, d, n, r;
int tmp, tl, tu, c0, ans, c_ip1;
char name[11];

class Array {
  public:
  int base;
  int size;
  int dimension;
  vector<int> upperBound, lowerBound;

  int getAddress(const vector<int>& add) const {
    c_ip1 = size;
    ans = c_ip1 * add[add.size()-1];
    c0  = base - c_ip1 * lowerBound[lowerBound.size()-1];
    
    for(i = add.size()-2; i>=0; --i){
      c_ip1 = c_ip1 * (upperBound[i+1]-lowerBound[i+1]+1);
      ans  += c_ip1 * add[i];
      c0   -= c_ip1 * lowerBound[i];
    }
    ans+=c0;
    return ans;
  }
};

int main() {
  map<string, int> nameMap;
  vector<int> arrayIndexes;

  scanf("%d %d", &n, &r);
  Array array[n];

  for(i=0; i<n; ++i) {
    scanf("%s %d %d %d", name, &array[i].base, &array[i].size, &array[i].dimension);
    for(d=0; d<array[i].dimension; ++d) {
      scanf("%d %d", &tl, &tu);
      array[i].lowerBound.push_back(tl);
      array[i].upperBound.push_back(tu);
    }

    nameMap[string(name)] = i;
  }

  for(;r>0; --r) {
    arrayIndexes.clear();
    scanf("%s", name);
    printf("%s[", name);
    const Array& ref = array[nameMap[string(name)]];
    for(i=0; i<ref.dimension; ++i) {
      scanf("%d", &tmp);
      printf("%d", tmp);
      if(i!=ref.dimension-1) printf(", ", tmp);
      arrayIndexes.push_back(tmp);
    }
    printf("] = %d\n", ref.getAddress(arrayIndexes));
  }
}
