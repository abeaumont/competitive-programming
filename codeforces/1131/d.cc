// https://codeforces.com/contest/1131/problem/D
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvi=vector<vi>;
int main(){
  int n,m;
  cin>>n>>m;
  vi s=vi(n+m, 1),p(n+m);
  for(int i=0;i<n+m;i++)p[i]=i;
  function<int(int)>find=[&](int i){
    if(i==p[i])return i;
    return p[i]=find(p[i]);
  };
  function<void(int,int)>unite=[&](int i,int j){
    i=find(i);
    j=find(j);
    if(i==j)return;
    if(s[i]<s[j])swap(i,j);
    s[i]+=s[j];
    p[j]=i;
  };
  vvi g(n+m);
  vii e;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<m;j++)
      if (s[j]=='>')e.push_back({i,n+j});
      else if(s[j]=='<')e.push_back({n+j,i});
      else unite(i,n+j);
  }
  for(ii x:e){
    int u,v;
    tie(u,v)=x;
    g[find(u)].push_back(find(v));
  }
  vi t(n+m),q;
  bool ok=1;
  function<void(int)>dfs=[&](int u){
    t[u]=1;
    for(int v:g[u])
      if(!t[v])dfs(v);
      else if(t[v]==1)ok=0;
    t[u]=2;
    q.push_back(u);
  };
  for(int i=0;i<n+m;i++)
    if(find(i)==i&&!t[i])
      dfs(i);
  if(!ok)cout<<"No\n";
  else{
    cout<<"Yes\n";
    vi r(n+m,1);
    for(int i=0;i<q.size();i++){
      int m=0;
      for(int u:g[q[i]])
        m=max(m,r[u]);
      r[q[i]]=m+1;
    }
    for(int i=0;i<n;i++)
      cout<<r[find(i)]<<" \n"[i==n-1];
    for(int i=0;i<m;i++)
      cout<<r[find(n+i)]<<" \n"[i==m-1];
  }
}
