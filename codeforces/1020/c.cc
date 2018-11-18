// https://codeforces.com/contest/1020/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ii=tuple<ll,ll>;
using vi=vector<ll>;
using vii=vector<ii>;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
  ll n,m,M=10000000000000000LL;
  cin>>n>>m;
  vii a;
  vi b(m);
  for(int i=0;i<n;i++){
    ll p,c;
    cin>>p>>c;
    p--;
    b[p]++;
    if(p) a.push_back({c,p});
  }
  sort(a.begin(),a.end());
  for (int i=1;i<=n;i++){
    vi d=b,e(a.size());
    ll p,c,k=0;
    for(int j=0;j<a.size();j++){
      tie(c,p)=a[j];
      if(d[p]>=i){
        d[p]--;
        k+=c;
        d[0]++;
        e[j]=1;
      }
    }
    for(int j=0;j<a.size();j++){
      if(d[0]>=i)break;
      if(e[j])continue;
      k+=get<0>(a[j]);
      d[0]++;
    }
    M=min(k,M);
  }
  cout<<M<<endl;
}
