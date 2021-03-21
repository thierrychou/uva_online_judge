#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n;
  unsigned long long a, i;
  while(cin>>n)
  {
    if(n<0)
      break;
    
    a=1;
    for(i=1; i<=n; ++i)
    {
      a+=i;
    }
    cout<<a<<endl;
  }
}
