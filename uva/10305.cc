// https://uva.onlinejudge.org/external/103/10305.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  for(;;){
    int n,m,u,v;
    cin>>n>>m;
    if(!n)break;
    vvi g(n);
    for(int i=0;i<m;i++){
      cin>>u>>v;
      u--;v--;
      g[u].push_back(v);
    }
    vi s(n),p;
    function<void(int)>dfs=[&](int u){
      s[u]=1;
      for(int v:g[u])
        if(!s[v])
          dfs(v);
      p.push_back(u);
    };
    for(int i=0;i<n;i++)
      if(!s[i])
        dfs(i);
    reverse(p.begin(),p.end());
    for(int i=0;i<n;i++)
      cout<<p[i]+1<<" \n"[i==n-1];
  }
}
