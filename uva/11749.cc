// https://uva.onlinejudge.org/external/117/11749.pdf
#include<bits/stdc++.h>
using namespace std;
using iii=tuple<int,int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
using viii=vector<iii>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int n,m,u,v,w,W=-2147483648,M=0;
    cin>>n>>m;
    if(!n)break;
    viii e(m);
    for(int i=0;i<m;i++){
      cin>>u>>v>>w;
      u--;v--;
      W=max(W,w);
      e[i]=make_tuple(u,v,w);
    }
    vvi g(n);
    for (iii &x:e){
      tie(u,v,w)=x;
      if(w==W){
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    vi s(n);
    function<void(int)>dfs=[&](int u){
      s[u]=1;
      for(int v:g[u])
        if(!s[v]){
          dfs(v);
          s[u]+=s[v];
        }
    };
    for(int i=0;i<n;i++)
      if(!s[i])
        dfs(i);
    for(int i=0;i<n;i++)M=max(M,s[i]);
    cout<<M<<"\n";
  }
}
