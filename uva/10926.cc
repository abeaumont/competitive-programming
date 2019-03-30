// https://uva.onlinejudge.org/external/109/10926.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using si=unordered_set<int>;
using vsi=vector<si>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int n,m,u,v;
    cin>>n;
    if(!n)break;
    vvi g(n);
    for(int i=0;i<n;i++){
      cin>>m;
      g[i]=vi(m);
      for(int j=0;j<m;j++){
        cin>>u;
        g[i][j]=u-1;
      }
    }
    vsi a(n);
    function<void(int)>dfs=[&](int u){
      a[u].insert(u);
      for(int v:g[u]){
        if(a[v].empty())dfs(v);
        for(int x:a[v])a[u].insert(x);
      }
    };
    for(int i=0;i<n;i++)
      if(a[i].empty())
        dfs(i);
    int M=0,k;
    for(int i=0;i<n;i++)
      if(a[i].size()>M){
        M=a[i].size();
        k=i+1;
      }
    cout<<k<<"\n";
  }
}
