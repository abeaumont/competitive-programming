// https://codeforces.com/contest/1020/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,h,a,b,k,ta,tb,fa,fb;
  cin>>n>>h>>a>>b>>k;
  for(int i=0;i<k;i++){
    cin>>ta>>fa>>tb>>fb;
    if(ta==tb){
      cout<<llabs(fa-fb)<<endl;
      continue;
    }
    ll c=llabs(tb-ta),s=0,t=0;
    if(fa>=a&&fa<=b)s=fa;
    else if(fa<a){s=a;c+=a-fa;}
    else{s=b;c+=fa-b;}
    if(fb>=a&&fb<=b)t=fb;
    else if(fb<a){t=a;c+=a-fb;}
    else{t=b;c+=fb-b;}
    c+=llabs(t-s);
    cout<<c<<endl;
  }
}
