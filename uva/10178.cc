// https://uva.onlinejudge.org/external/101/10178.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m){
    vi s(128,-1);
    vvi g(n);
    char a,b;
    int c=0;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      if(s[a]==-1)s[a]=c++;
      if(s[b]==-1)s[b]=c++;
      g[s[a]].push_back(s[b]);
      g[s[b]].push_back(s[a]);
    }
    vi t(n);
    int x,y;
    function<void(int,int)>dfs=[&](int u,int k){
      t[u]=k;
      x++;
      for(int v:g[u]){
        y++;
        if(!t[v])
          dfs(v,k);
      }
    };
    int z=0;
    for(int i=0,k=1;i<n;i++)
      if(!t[i]){
        x=0;
        y=0;
        dfs(i,k++);
        z+=y/2-x+1;
      }
    cout<<++z<<"\n";
  }
}
