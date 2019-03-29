// https://uva.onlinejudge.org/external/3/315.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvi=vector<vi>;
using vvii=vector<vii>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int n,m,u,v;
    string s;
    cin>>n;
    if(!n)break;
    getline(cin,s);
    vvi g(n);
    for(;;){
      getline(cin,s);
      stringstream in(s);
      in>>u;
      if(!u)break;
      u--;
      while(in>>v){
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
      }
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
    int x=0;
    for(int i=0;i<n;i++)x+=d[i];
    cout<<x<<"\n";
  }
}
