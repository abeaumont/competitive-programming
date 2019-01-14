// https://open.kattis.com/problems/falling
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll d;
  cin>>d;
  for(ll i=0;(i+1)*(i+1)-i*i<=d;i++){
    ll n2=d+i*i;
    ll n=sqrt(n2);
    if(n*n==n2){
      cout<<i<<" "<<n<<"\n";
      return 0;
    }
  }
  cout<<"impossible\n";
}
