// https://open.kattis.com/problems/reversingroads
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  for(int T=1;cin>>n>>m;T++){
    vvi g(n),h(n);
    vii e;
    for(int i=0;i<m;i++){
      cin>>u>>v;
      g[u].push_back(v);
      h[v].push_back(u);
      e.emplace_back(u,v);
    }
    vi a,s(n),t(n),r(n);
    function<void(int)> dfs1=[&](int i){
      s[i]=1;
      for(int j:g[i])
        if(!s[j])dfs1(j);
      a.push_back(i);
    };
    for(int i=0;i<n;i++)
      if(!s[i])dfs1(i);
    reverse(a.begin(),a.end());
    int k=0;
    function<void(int)> dfs2=[&](int i){
      t[i]=k;
      for(int j:h[i])
        if(!t[j])dfs2(j);
    };
    for(int i=0;i<a.size();i++)
      if(!t[a[i]]){
        k++;
        dfs2(a[i]);
      }
    function<void(int)>dfs3=[&](int i){
      r[i]=1;
      for(int j:g[i])
        if(!r[j])dfs3(j);
    };
    for(int i=0;i<n;i++)
      if(t[i]==1){
        dfs3(i);
        break;
      }
    bool o=1;
    for(int i=0;i<n;i++){
      if(!r[i])o=0;
    }
    cout<<"Case "<<T<<": ";
    if(k==1){
      cout<<"valid\n";
      continue;
    }
    if(!o){
      cout<<"invalid\n";
      continue;
    }
    vii f;
    for(ii x:e){
      tie(u,v)=x;
      if(t[u]==1&&t[v]==k)f.push_back(x);
    }
    if((k==2&&f.size()>=2)||(k>2&&f.size())){
      tie(u,v)=f[0];
      cout<<u<<" "<<v<<"\n";
    }else cout<<"invalid\n";
  }
}
