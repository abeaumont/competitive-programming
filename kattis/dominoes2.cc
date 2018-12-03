// https://open.kattis.com/problems/dominoes2
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
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
    vi a(n);
    function<void(int)>dfs=[&](int u){
      if(a[u])return;
      a[u]++;
      for(int v:g[u]){
        if(a[v])continue;
        dfs(v);
      }
    };
    for(int i=0;i<l;i++){
      cin>>u;
      dfs(u-1);
    }
    int c=0;
    for(int i=0;i<n;i++)c+=a[i];
    cout<<c<<endl;
  }
}
