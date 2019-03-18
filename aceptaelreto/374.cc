// https://www.aceptaelreto.com/problem/statement.php?id=374
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,a,b,c,d;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>a;
    b=a;
    c=d=1;
    while(1){
      ll x;
      cin>>x;
      if(!x)break;
      if(x<a){
        a=x;
        c=1;
      }else if(x==a)c++;
      if(x>b){
        b=x;
        d=1;
      }else if(x==b)d++;
    }
    printf("%lld %lld %lld %lld\n",a,c,b,d);
  }
}
