// https://codeforces.com/problemsets/acmsguru/problem/99999/102
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,c=0;
  cin>>n;
  for(int i=1;i<=n;i++)
    c+=__gcd(i,n)==1;
  cout<<c<<"\n";
}
