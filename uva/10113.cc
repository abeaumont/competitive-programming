// https://uva.onlinejudge.org/external/101/10113.pdf
#include<bits/stdc++.h>
using namespace std;
using msi=unordered_map<string,int>;
using iii=tuple<int,int,int>;
using vi=vector<int>;
using viii=vector<iii>;
using vviii=vector<viii>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char o;
  int a,b,n=0;
  string x,y;
  msi m;
  vviii g;
  for(;;){
    cin>>o;
    if(o=='.')break;
    if(o=='!'){
      cin>>a>>x>>o>>b>>y;
      if(!m[x])m[x]=++n;
      if(!m[y])m[y]=++n;
      while(g.size()<n)g.push_back(viii());
      int k=__gcd(a,b);
      g[m[x]-1].emplace_back(m[y]-1,a/k,b/k);
      g[m[y]-1].emplace_back(m[x]-1,b/k,a/k);
    }else{
      cin>>x>>o>>y;
      if(m[x]&&m[y]){
        vi c(n),d(n);
        function<void(int)>dfs=[&](int u){
          for(iii x:g[u]){
            int v,a,b;
            tie(v,a,b)=x;
            if(!c[v]){
              int p=c[u]*a,q=d[u]*b;
              int k=__gcd(p,q);
              p/=k;q/=k;
              c[v]=p;d[v]=q;
              dfs(v);
            }
          }
        };
        int u=m[x]-1,v=m[y]-1;
        c[u]=d[u]=1;
        dfs(u);
        if(c[v])cout<<c[v]<<" "<<x<<" = "<<d[v]<<" "<<y<<"\n";
        else cout<<"? "<<x<<" = ? "<<y<<"\n";
      }else cout<<"? "<<x<<" = ? "<<y<<"\n";
    }
  }
}
