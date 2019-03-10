// https://uva.onlinejudge.org/external/105/10583.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  for(int t=1;;t++){
    int n,m,u,v;
    cin>>n>>m;
    if(!n)break;
    vvi g(n);
    for(int i=0;i<m;i++){
      cin>>u>>v;
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
    cout<<"Case "<<t<<": "<<k-1<<endl;
  }
}
