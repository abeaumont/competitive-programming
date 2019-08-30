// https://cses.fi/problemset/task/1196/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll>ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef priority_queue<ii,vii,greater<ii>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  vvii g(n);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    g[u].push_back({w,v});
  }
  int c=0;
  vi b(n,0);
  pq q;
  q.push({0,0});
  while(true){
    ll w,u;
    tie(w,u)=q.top();
    q.pop();
    if(b[u]>k)continue;
    if(u==n-1){
      c++;
      cout<<w<<" \n"[c==k];
      if(c==k)break;
    }
    b[u]++;
    for(auto z:g[u]){
      ll x,v;
      tie(x,v)=z;
      if (b[v]>k)continue;
      q.push({w+x,v});
    }
  }
}
