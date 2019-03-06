// https://uva.onlinejudge.org/external/100/10004.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using qi=queue<int>;
int main(){
  int n,m,u,v;
  for(;;){
    cin>>n>>m;
    if(!n)break;
    vvi g(n);
    for(int i=0;i<m;i++){
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi p(n),c(n);
    qi q;
    q.push(0);
    p[0]=-1;
    c[0]=2;
    bool ok=1;
    while(!q.empty()){
      u=q.front();
      int z=c[u]%2+1;
      q.pop();
      for(int k:g[u]){
        if(!c[k]){
          p[k]=u;
          q.push(k);
          c[k]=z;
        }else if(z!=c[k]){
          ok=0;
          break;
        }
      }
      if(!ok)break;
    }
    if(ok)cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";
  }
}
