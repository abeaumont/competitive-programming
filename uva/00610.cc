// https://uva.onlinejudge.org/external/6/610.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvi=vector<vi>;
int main(){
  for(int T=1;;T++){
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
    vi a(n),b(n);
    vii e;
    int k=1;
    function<void(int,int)>dfs=[&](int u,int p){
      a[u]=k++;
      b[u]=a[u];
      for(int v:g[u]){
        if(!a[v]||(v!=p&&a[v]<a[u]))e.emplace_back(u,v);
        if(!a[v]){
          dfs(v,u);
          b[u]=min(b[u],b[v]);
          if(b[v]>a[u])e.emplace_back(v,u);
        }else if(v!=p)b[u]=min(b[u],a[v]);
      }
    };
    for(int i=0;i<n;i++)
      if(!a[i])
        dfs(i,-1);
    sort(e.begin(),e.end());
    cout<<T<<"\n\n";
    for(ii x:e){
      tie(u,v)=x;
      cout<<u+1<<" "<<v+1<<"\n";
    }
    cout<<"#\n";
  }
}
