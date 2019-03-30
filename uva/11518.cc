// https://uva.onlinejudge.org/external/115/11518.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,m,l,u,v;
  cin>>t;
  while(t--){
    cin>>n>>m>>l;
    vvi g(n);
    for(int i=0;i<m;i++){
      cin>>u>>v;
      u--;v--;
      g[u].push_back(v);
    }
    vi s(n);
    function<void(int)>dfs=[&](int u){
      s[u]=1;
      for(int v:g[u])
        if(!s[v])
          dfs(v);
    };
    for(int i=0;i<l;i++){
      cin>>u;
      u--;
      if(!s[u])
        dfs(u);
    }
    int c=0;
    for(int x:s)c+=x;
    cout<<c<<"\n";
  }
}
