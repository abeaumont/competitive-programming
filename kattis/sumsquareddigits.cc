// https://open.kattis.com/problems/sumsquareddigits
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p,k,b,n;
  cin>>p;
  while(p--){
    cin>>k>>b>>n;
    ll x,c=0;
    while(n){
      x=n%b;
      c+=x*x;
      n/=b;
    }
    cout<<k<<" "<<c<<"\n";
  }
}
