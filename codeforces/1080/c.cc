// https://codeforces.com/contest/1080/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll wr(ll x1,ll y1,ll x2,ll y2){
  if(y2<y1||x2<x1)return 0;
  ll n=y2-y1+1,m=x2-x1+1;
  if(n%2&&m%2){
    if(x1%2==y1%2)
      return((n+1)/2)*((m+1)/2)+(n/2)*(m/2);
    return (n/2)*((m+1)/2)+((n+1)/2)*(m/2);
  }
  return n*m/2;
}

ll br(ll x1,ll y1,ll x2,ll y2){
  if(y2<y1||x2<x1)return 0;
  return (y2-y1+1)*(x2-x1+1)-wr(x1,y1,x2,y2);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    ll n,m,x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>n>>m>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    ll w=wr(1,1,m,n);
    w+=br(x1,y1,x2,y2);
    w-=wr(x3,y3,x4,y4);
    w-=br(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
    cout<<w<<" "<<n*m-w<<endl;
  }
}
