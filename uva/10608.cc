// https://uva.onlinejudge.org/external/106/10608.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int t,n,m,u,v;
  cin>>t;
  while(t--){
    cin>>n>>m;
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
    vi s(k);
    for(int i=0;i<n;i++)
      s[c[i]]++;
    int M=0;
    for(int x:s)M=max(M,x);
    cout<<M<<endl;
  }
}
