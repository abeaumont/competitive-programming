// https://cses.fi/problemset/task/1195
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef priority_queue<ii, vii, greater<ii>> q;

ll INF = 1LL << 62;

void f(vvii &g, vi &d, int s) {
  q q;
  q.push({0, s});
  while (!q.empty()) {
    ll c, u, v, w;
    tie(c, u) = q.top(); q.pop();
    if (d[u] < c) continue;
    for (ii x : g[u]) {
      tie(v, w) = x;
      if (d[v] > c + w)
        d[v] = c + w, q.push({c + w, v});
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  viii e(m);
  vvii g(n), h(n);
  ll a, b, c, r = INF;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    h[b].push_back({a, c});
    e.emplace_back(a, b, c);
  }
  vi d(n, INF), di(n, INF);
  f(g, d, 0);
  f(h, di, n - 1);
  d[0] = 0, di[n - 1] = 0;
  for (iii x : e) {
    tie(a, b, c) = x;
    r = min(r, d[a] + di[b] + c / 2);
  }
  cout << r << "\n";
}
