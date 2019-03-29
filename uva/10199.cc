// https://uva.onlinejudge.org/external/101/10199.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=unordered_map<string,int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int T=1;;T++){
    int n,m,u,v;
    cin>>n;
    if(!n)break;
    msi c;
    vs x(n);
    for(int i=0;i<n;i++){
      cin>>x[i];
      c[x[i]]=i;
    }
    cin>>m;
    vvi g(n);
    for(int i=0;i<m;i++){
      string s,t;
      cin>>s>>t;
      u=c[s];v=c[t];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi a(n),b(n),d(n);
    int k=1;
    function<void(int,int)>dfs=[&](int u,int p){
      a[u]=k++;
      b[u]=a[u];
      int c=0;
      for(int v:g[u])
        if(!a[v]){
          c++;
          dfs(v,u);
          b[u]=min(b[u],b[v]);
          if(b[v]>=a[u])d[u]=1;
        }else if(v!=p)b[u]=min(b[u],a[v]);
      if(p==-1)d[u]=c>1;
    };
    for(int i=0;i<n;i++)
      if(!a[i])
        dfs(i,-1);
    vs r;
    for(int i=0;i<n;i++)
      if(d[i])
        r.push_back(x[i]);
    if(T>1)cout<<"\n";
    cout<<"City map #"<<T<<": "<<r.size()<<" camera(s) found\n";
    sort(r.begin(),r.end());
    for(string &x:r)cout<<x<<"\n";
  }
}
