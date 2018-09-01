// https://cses.fi/problemset/task/1195
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef priority_queue<iii, viii, greater<iii>> q;

const ll INF = 1LL << 62;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvii g(n);
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].push_back({b, c});
  }
  vi d(n, INF);
  vb s(n);
  q q;
  q.push({0, 0, 0});
  while (true) {
    assert(!q.empty());
    ll c, u, m;
    tie(c, u, m) = q.top(); q.pop();
    if (u == n - 1) {
      cout << c - (m - m/2) << endl;
      break;
    }
    s[u] = true;
    for (auto z:g[u]) {
      ll v, e;
      tie(v, e) = z;
      if (s[v]) continue;
      ll f = c + e;
      if (f < d[v]) {
        d[v] = f;
        q.push({f, v, max(m, e)});
      }
    }
  }
}
