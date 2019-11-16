// https://codeforces.com/contest/1080/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll q,l,r;
  cin>>q;
  while(q--){
    cin>>l>>r;
    ll a=l/2;
    if(!(l%2))a=-a;
    ll b=(r+1)/2;
    if(r%2)b=-b;
    cout<<b-a<<endl;
  }
}
