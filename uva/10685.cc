// https://uva.onlinejudge.org/external/106/10685.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using msi=unordered_map<string,int>;
int main(){
  int n,m,u,v;
  while(1){
    cin>>n>>m;
    if(!n)break;
    vvi g(n);
    int k=0;
    msi d;
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      d[s]=k++;
    }
    for(int i=0;i<m;i++){
      string s,t;
      cin>>s>>t;
      u=d[s];v=d[t];
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
    k=1;
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
