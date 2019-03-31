// https://uva.onlinejudge.org/external/117/11770.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using qi=queue<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,m,u,v;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>n>>m;
    vvi g(n),h(n),c;
    for(int i=0;i<m;i++){
      cin>>u>>v;
      u--;v--;
      g[u].push_back(v);
      h[v].push_back(u);
    }
    vi a,s(n),t(n),r(n);
    function<void(int)>dfs1=[&](int i){
      s[i]=1;
      for(int j:g[i])
        if(!s[j])dfs1(j);
      a.push_back(i);
    };
    for(int i=0;i<n;i++)
      if(!s[i])dfs1(i);
    reverse(a.begin(),a.end());
    function<void(int)>dfs2=[&](int i){
      t[i]=1;
      c.back().push_back(i);
      for(int j:h[i])
        if(!t[j])dfs2(j);
    };
    for(int i=0;i<a.size();i++)
      if(!t[a[i]]){
        c.push_back(vi());
        dfs2(a[i]);
      }
    function<void(int)>dfs3=[&](int i){
      r[i]=1;
      for(int j:g[i])
        if(!r[j])dfs3(j);
    };
    int k=0;
    for(vi &x:c)
      if(!r[x[0]]){
        k++;
        dfs3(x[0]);
      }
    cout<<"Case "<<T<<": "<<k<<"\n";
  }
}
