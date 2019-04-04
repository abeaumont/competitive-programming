// https://uva.onlinejudge.org/external/3/336.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vi=vector<int>;
using vvi=vector<vi>;
using mii=unordered_map<int,int>;
using qi=queue<int>;
int main(){
  for(int T=1;;){
    int m,u,v,w,n=0,k;
    cin>>m;
    if(!m)break;
    mii x;
    vii e(m);
    for(int i=0;i<m;i++){
      cin>>u>>v;
      if(!x[u])x[u]=++n;
      if(!x[v])x[v]=++n;
      e[i]=make_tuple(x[u]-1,x[v]-1);
    }
    vvi g(n);
    for(ii a:e){
      tie(u,v)=a;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for(;;){
      cin>>w>>k;
      if(!w)break;
      u=x[w]-1;
      vi s(n);
      if(u>=0){
        s[u]=1;
        qi q;
        q.push(u);
        while(!q.empty()){
          u=q.front();
          q.pop();
          if(s[u]<=k)
            for(int v:g[u])
              if(!s[v]){
                s[v]=s[u]+1;
                q.push(v);
              }
        }
      }
      int c=0;
      for(int x:s)c+=(!x);
      cout<<"Case "<<T++<<": "<<c<<" nodes not reachable from node "<<w<<" with TTL = "<<k<<".\n";
    }
  }
}
