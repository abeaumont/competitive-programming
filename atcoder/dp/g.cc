// https://atcoder.jp/contests/dp/tasks/dp_g
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using qi=queue<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  cin>>n>>m;
  vvi g(n);
  vi a(n),b(n);
  for(int i=0;i<m;i++){
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    a[v]++;
  }
  qi q;
  for(int i=0;i<n;i++)
    if(!a[i])
      q.push(i);
  while(!q.empty()){
    u=q.front();
    q.pop();
    for(int v:g[u]){
      b[v]=max(b[v],1+b[u]);
      a[v]--;
      if(!a[v])
        q.push(v);
    }
  }
  int c=0;
  for(int i=0;i<n;i++)c=max(c,b[i]);
  cout<<c<<"\n";
}
