// https://www.hackerrank.com/challenges/components-in-graph
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  cin>>m;
  n=2*m;
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
  int N=n,M=0;
  for(int x:s){
    if(x>1)N=min(N,x);
    M=max(M,x);
  }
  cout<<N<<" "<<M<<endl;
}
