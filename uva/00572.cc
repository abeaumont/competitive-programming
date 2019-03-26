// https://uva.onlinejudge.org/external/5/572.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vs=vector<string>;
using vii=vector<ii>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  while(1){
    cin>>n>>m;
    if(!n)break;
    vii e;
    vs s(n);
    vvi b(n,vi(m));
    for(int i=0;i<n;i++)cin>>s[i];
    int k=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(s[i][j]=='@'){
          k++;
          b[i][j]=k;
          if(i>0&&b[i-1][j])e.push_back(make_tuple(b[i-1][j],b[i][j]));
          if(i<n-1&&b[i+1][j])e.push_back(make_tuple(b[i+1][j],b[i][j]));
          if(j>0&&b[i][j-1])e.push_back(make_tuple(b[i][j-1],b[i][j]));
          if(j<m-1&&b[i][j+1])e.push_back(make_tuple(b[i][j+1],b[i][j]));
          if(i>0&&j>0&&b[i-1][j-1])e.push_back(make_tuple(b[i-1][j-1],b[i][j]));
          if(i<n-1&&j>0&&b[i+1][j-1])e.push_back(make_tuple(b[i+1][j-1],b[i][j]));
          if(i>0&&j<m-1&&b[i-1][j+1])e.push_back(make_tuple(b[i-1][j+1],b[i][j]));
          if(i<n-1&&j<m-1&&b[i+1][j+1])e.push_back(make_tuple(b[i+1][j+1],b[i][j]));
        }
    vvi g(k);
    for(ii x:e){
      tie(u,v)=x;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi c(k);
    function<void(int)>dfs=[&](int u){
      c[u]=1;
      for(int v:g[u])
        if(!c[v])
          dfs(v);
    };
    int l=0;
    for(int i=0;i<k;i++)
      if(!c[i]){
        l++;
        dfs(i);
      }
    cout<<l<<"\n";
  }  
}
