// https://uva.onlinejudge.org/external/118/11838.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using si=unordered_set<int>;
using vsi=vector<si>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    int n,m,u,v,p;
    cin>>n>>m;
    if(!n)break;
    vsi g(n),h(n);
    for(int i=0;i<m;i++){
      cin>>u>>v>>p;
      u--;v--;
      g[u].insert(v);
      h[v].insert(u);
      if(p==2){
        g[v].insert(u);
        h[u].insert(v);
      }
    }
    vi s(n),t(n);
    int k;
    function<void(int)> dfs1=[&](int i){
      s[i]=1;
      for(int j:g[i])
        if(!s[j])dfs1(j);
      k=i;
    };
    for(int i=0;i<n;i++)
      if(!s[i])dfs1(i);
    function<void(int)> dfs2=[&](int i){
      t[i]=1;
      for(int j:h[i])
        if(!t[j])dfs2(j);
    };
    dfs2(k);
    int c=1;
    for(int i=0;i<n;i++)
      if(!t[i]){
        c=0;
        break;
      }
    cout<<c<<"\n";
  }
}
