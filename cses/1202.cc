// https://cses.fi/problemset/task/1202/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef priority_queue<iii, vector<iii>, greater<iii>> qiii;

ll M=1000000007;

int main() {
  ll n,m,x,y,u,v,w;
  cin>>n>>m;
  vvii g(n);
  for (int i=0;i<m;i++) {
    cin>>u>>v>>w;
    u--;v--;
    g[u].push_back({v,w});
  }
  vi a(n,0),b(n,0);
  vvi p(n);
  qiii q;
  q.push({0,0,-1});
  while (!q.empty()) {
    tie(w,u,v)=q.top();
    q.pop();
    if(a[u]&&b[u]<w) continue;
    a[u]++;
    b[u]=w;
    if (v!=-1) p[u].push_back(v);
    if (a[u]>1) continue;
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
  int tn=t.size();
  for (int i=0;i<tn;i++) ti[t[i]]=i;
  vi c(tn),d(tn,b[n-1]),e(tn);
  c[0]=1;
  d[0]=0;
  for (int i=0;i<tn;i++)
    for (int u:h[t[i]]) {
      c[ti[u]]=(c[ti[u]]+c[i])%M;
      d[ti[u]]=min(d[ti[u]],1+d[i]);
      e[ti[u]]=max(e[ti[u]],1+e[i]);
    }
  printf("%lld %lld %lld %lld\n",b[n-1],c[tn-1],d[tn-1],e[tn-1]);
}
