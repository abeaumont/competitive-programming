// https://codeforces.com/contest/1061/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
int main(){
  ll n,m,t=0;
  cin>>n>>m;
  vi a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    t+=a[i];
  }
  sort(a.begin(),a.end());
  ll c=0,k=0;
  for(ll i=0;i<n;i++){
    if(!a[i])continue;
    if(a[i]>k)k++;
    c++;
  }
  c+=a[n-1]-k;
  cout<<t-c<<endl;
}
