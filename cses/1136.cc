// https://cses.fi/problemset/stats/1136/
#include <bits/stdc++.h>

using namespace std;
using si=unordered_set<int>;
using vb=vector<bool>;
using vi=vector<int>;
using vvi=vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  cin>>n>>m;
  vvi g(n),h(n);
  for (int i=0;i<n-1;i++) {
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i=0;i<m;i++) {
    cin>>u>>v;
    u--;v--;
    h[u].push_back(i);
    h[v].push_back(i);
  }
  vi a(n);
  vb s(n);
  function<si(int)> dfs=[&](int u) {
    si t;
    s[u]=1;
    for (int v:g[u]) {
      if (s[v]) continue;
      si x=dfs(v);
      a[u]+=x.size();
      if (x.size()>t.size()) swap(x,t);
      for (int y:x)
        if (t.count(y)) t.erase(y);
        else t.insert(y);
    }
    a[u]=(a[u]-t.size())/2+t.size();
    for (int v:h[u])
      if (t.count(v)) t.erase(v);
      else {
        a[u]++;
        t.insert(v);
      }
    return t;
  };
  dfs(0);
  for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
}
