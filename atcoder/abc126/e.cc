// https://atcoder.jp/contests/abc126/tasks/abc126_e
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v,z;
  cin>>n>>m;
  vvi g(n);
  for(int i=0;i<m;i++){
    cin>>u>>v>>z;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi c(n);
  function<void(int,int)>dfs=[&](int u,int k){
    c[u]=k;
    for(int v:g[u])
      if(!c[v])
        dfs(v,k);
  };
  int k=1;
  for(int i=0;i<n;i++)
    if(!c[i])
      dfs(i,k++);
  cout<<k-1<<"\n";
}
