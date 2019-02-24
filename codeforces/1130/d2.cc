// https://codeforces.com/contest/1130/problem/D2
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,m;
  cin>>n>>m;
  vvi c(n);
  for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    c[a].push_back(b);
  }
  vi d(n);
  for(ll i=0;i<n;i++){
    ll x=n;
    ll k;
    for(ll z:c[i]){
      ll y=z-i;
      if(y<0)y+=n;
      if(y<x){
        x=y;
        k=z;
      }
    }
    d[i]=k;
  }
  for(ll i=0;i<n;i++){
    ll M=0;
    for(ll j=0;j<n;j++)
      if(c[j].size()){
        ll s=0;
        s+=j-i;
        if(i>j)s+=n;
        s+=(c[j].size()-1)*n;
        s+=d[j]-j;
        if(j>d[j])s+=n;
        M=max(M,s);
      }
    cout<<M<<" \n"[i==n-1];
  }
}
