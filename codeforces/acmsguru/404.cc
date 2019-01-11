// https://codeforces.com/problemsets/acmsguru/problem/99999/404
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  string s;
  for(int i=0;i<=(n-1)%m;i++)cin>>s;
  cout<<s<<"\n";
}
