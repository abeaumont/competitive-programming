// https://uva.onlinejudge.org/external/116/11690.pdf
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t,n,m,u,v;
  cin>>t;
  while(t--){
    cin>>n>>m;;
    vi a(n);
    vvi g(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<m;i++){
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi s(n);
    function<void(ll,ll)>dfs=[&](ll u,ll k){
      s[u]=k;
      for(ll v:g[u])
        if(!s[v])
          dfs(v,k);
    };
    ll k=1;
    for(ll i=0;i<n;i++)
      if(!s[i])
        dfs(i,k++);
    vi r(k);
    for(ll i=0;i<n;i++)r[s[i]]+=a[i];
    ll o=1;
    for(ll i=1;i<k;i++)
      if(r[i])o=0;
    cout<<(o?"":"IM")<<"POSSIBLE\n";
  }
}
