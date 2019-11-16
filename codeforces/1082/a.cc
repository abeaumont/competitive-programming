// https://codeforces.com/contest/1082/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll t,n,x,y,d;
  cin>>t;
  while(t--){
    cin>>n>>x>>y>>d;
    if((y-x)%d==0)cout<<llabs(y-x)/d<<endl;
    else if((n-y)%d==0&&(y-1)%d==0){
      ll a=(n-x-1)/d+1+(n-y)/d;
      ll b=(x-1)/d+1+(y-1)/d;
      cout<<min(a,b)<<endl;
    }else if((n-y)%d==0){
      cout<<(n-x-1)/d+1+(n-y)/d<<endl;
    }else if((y-1)%d==0){
      cout<<(x-1)/d+1+(y-1)/d<<endl;
    }else cout<<"-1\n";
  }
}
