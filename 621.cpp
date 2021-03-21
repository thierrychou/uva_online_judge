#include <iostream>

using namespace std;

int n, length;
string num;

int main() {
  cin >> n;
  for(; n>0; --n) {
    cin >> num;
    length = num.length();
    
    if(num=="1"||num=="4"||num=="78") {
      cout<<'+'<<endl;
    } else if(num[length-2]=='3' && num[length-1]=='5') {
      cout<<'-'<<endl;
    } else if(num[0]=='9' && num[length-1]=='4') {
      cout<<'*'<<endl;
    } else if(num[0]=='1' && num[1]=='9' && num[2]=='0') {
      cout<<'?'<<endl;
    }
  }
}
