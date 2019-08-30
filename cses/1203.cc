// https://cses.fi/problemset/task/1203/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef priority_queue<iii,viii,greater<iii>> pq;
typedef unordered_set<ll> si;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,m,u,v,w,x,y;
  cin>>n>>m;
  vvii g(n);
  for (int i=0;i<m;i++) {
    cin>>u>>v>>w;
    u--;v--;
    g[u].push_back({v,w});
  }
  vi c(n),d(n);
  vvi p(n);
  pq q;
  q.push({0,0,-1});
  while (!q.empty()) {
    tie(w,u,v)=q.top();
    q.pop();
    if(c[u]&&d[u]<w) continue;
    c[u]++;
    d[u]=w;
    if (v!=-1) p[u].push_back(v);
    if (c[u]>1) continue;
    for (auto z:g[u]) {
      tie(x,y)=z;
      q.push({w+y,x,u});
    }
  }
  vb s(n);
  vvi h(n);
  vi o;
  o.push_back(n-1);
  while (!o.empty()) {
    u = o.back();
    o.pop_back();
    if (s[u]) continue;
    s[u]=true;
    for (int v:p[u]) {
      h[v].push_back(u);
      o.push_back(v);
    }
  }
  vb r(n);
  vi t;
  function<void(int)> dfs = [&](int u) {
    r[u]=true;
    for (int v:h[u])
      if (!r[v]) dfs(v);
    t.push_back(u);
  };
  dfs(0);
  reverse(t.begin(), t.end());
  vi ti(n, -1);
  for (int i=0;i<t.size();i++) ti[t[i]]=i;
  vi e;
  ll z=0;
  for (int i=0;i<t.size();i++) {
    if(i==z) e.push_back(t[i]);
    for (int u:h[t[i]]) z=max(z,ti[u]);
  }
  sort(e.begin(),e.end());
  cout<<e.size()<<endl;
  for (int i=0;i<e.size();i++)
    cout<<e[i]+1<<" \n"[i==e.size()-1];
}
