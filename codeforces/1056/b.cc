// https://codeforces.com/contest/1056/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,m;
  cin>>n>>m;
  ll k=0;
  for(ll i=1;i<=min(n,m);i++){
    ll c=0;
    for (ll j=1;j<=min(n,m);j++)
      if(((i%m)*(i%m)+(j%m)*(j%m))%m==0){
        c+=n/m;
        if(n%m>0&&j<=n%m)c++;
      }
    ll r=n/m;
    if(n%m>0&&i<=n%m)r++;
    k+=c*r;
  }
  cout<<k<<endl;
}
