// https://codeforces.com/contest/1151/problem/D
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ii=tuple<ll,ll>;
using vi=vector<ll>;
using vii=vector<ii>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,x,y;
  cin>>n;
  vii a(n),b(n);
  for(ll i=0;i<n;i++){
    cin>>x>>y;
    a[i]={x,y};
    b[i]={y-x,i};
  }
  sort(b.begin(),b.end());
  ll c=0;
  for(ll i=0;i<n;i++){
    tie(x,y)=a[get<1>(b[i])];
    c+=x*i+y*(n-i-1);
  }
  cout<<c<<"\n";
}
