// https://codeforces.com/contest/1082/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ll n,m,s,r;
  cin>>n>>m;
  vvi a(m);
  for(int i=0;i<n;i++){
    cin>>s>>r;
    s--;
    a[s].push_back(r);
  }
  for(int i=0;i<m;i++){
    sort(a[i].rbegin(),a[i].rend());
    for(int j=1;j<a[i].size();j++)a[i][j]+=a[i][j-1];
  }
  sort(a.begin(),a.end(),[&](vi &u, vi &v){return u.size()>v.size();});
  ll M=0;
  for(int i=1;i<=a[0].size();i++){
    ll c=0;
    for(int j=0;j<m&&a[j].size()>=i;j++)c+=max(0,a[j][i-1]);
    M=max(M,c);
  }
  cout<<M<<endl;
}
