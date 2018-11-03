// https://codeforces.com/contest/1043/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,s=0,x,m=0;
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>x;
    m=max(m,x);
    s+=x;
  }
  cout<<max(m,2*s/n+1)<<endl;
}
