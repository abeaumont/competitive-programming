// https://uva.onlinejudge.org/external/7/796.pdf
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
  int n,m,u,v;
  while(cin>>n){
    string s;
    getline(cin,s);
    vvi g(n);
    for(;;){
      getline(cin,s);
      if(s.empty())break;
      stringstream in(s);
      string r;
      in>>u>>r;
      while(in>>v){
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    vi a(n),b(n);
    vii e;
    int k=1;
    function<void(int,int)>dfs=[&](int u,int p){
      a[u]=k++;
      b[u]=a[u];
      for(int v:g[u])
        if(!a[v]){
          dfs(v,u);
          b[u]=min(b[u],b[v]);
          if(b[v]>a[u])e.emplace_back(min(u,v),max(u,v));
        }else if(v!=p)b[u]=min(b[u],a[v]);
    };
    for(int i=0;i<n;i++)
      if(!a[i])
        dfs(i,-1);
    cout<<e.size()<<" critical links\n";
    sort(e.begin(),e.end());
    for(ii x:e){
      tie(u,v)=x;
      cout<<u<<" - "<<v<<"\n";
    }
    cout<<"\n";
  }
}
