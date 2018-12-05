// https://codeforces.com/contest/1079/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  int n=s.size();
  int r=(n-1)/20+1;
  int c=(n-1)/r+1;
  int k=r*c-n;
  cout<<r<<" "<<c<<endl;
  for(int l=0,i=0;i<r;i++) {
    for(int j=0;j<c;j++)
      if(j==c-1&&i<k)cout<<'*';
      else cout<<s[l++];
    cout<<endl;
  }
}
