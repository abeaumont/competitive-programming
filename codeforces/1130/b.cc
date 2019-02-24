// https://codeforces.com/contest/1130/problem/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin>>n;
  vvi a(n);
  for(ll i=0;i<2*n;i++){
    ll x;
    cin>>x;
    x--;
    a[x].push_back(i);
  }
  ll x=0,y=0;
  ll k=0;
  for(ll i=0;i<n;i++){
    ll p1=a[i][0];
    ll p2=a[i][1];
    if(llabs(p1-x)+llabs(p2-y)<=llabs(p2-x)+llabs(p1-y)){
      k+=llabs(p1-x)+llabs(p2-y);
      x=p1;
      y=p2;
    }else{
      k+=llabs(p1-y)+llabs(p2-x);
      x=p2;
      y=p1;
    }
  }
  cout<<k<<endl;
}
