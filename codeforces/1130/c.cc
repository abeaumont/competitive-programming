// https://codeforces.com/contest/1130/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,r1,c1,r2,c2;
  cin>>n>>r1>>c1>>r2>>c2;
  r1--;c1--;r2--;c2--;
  vs a(n);
  for(ll i=0;i<n;i++)cin>>a[i];
  vvi s(n, vi(n));
  function<void(ll,ll,ll)>dfs=[&](ll y,ll x, ll k){
    s[y][x]=k;
    if(y>0&&!s[y-1][x]&&a[y-1][x]=='0')dfs(y-1,x,k);
    if(y<n-1&&!s[y+1][x]&&a[y+1][x]=='0')dfs(y+1,x,k);
    if(x>0&&!s[y][x-1]&&a[y][x-1]=='0')dfs(y,x-1,k);
    if(x<n-1&&!s[y][x+1]&&a[y][x+1]=='0')dfs(y,x+1,k);
  };
  dfs(r1,c1,1);
  if(s[r2][c2]){
    cout<<0<<endl;
    return 0;
  }
  dfs(r2,c2,2);
  ll m=(r1-r2)*(r1-r2)+(c1-c2)*(c1-c2);
  for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)
      for(ll k=0;k<n;k++)
        for(ll l=0;l<n;l++)
          if(s[i][j]==1&&s[k][l]==2)
            m=min(m,(i-k)*(i-k)+(j-l)*(j-l));
  cout<<m<<endl;
}
