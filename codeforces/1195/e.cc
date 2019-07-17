// https://codeforces.com/contest/1195/problem/E
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<ll, int>;
using q = deque<ii>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
	ll n, m, a, b, g0, x, y, z;
	cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
  vector<ll> g(n * m);
  vvi c(n, vi(m - b + 1));
  g[0] = g0;
  for (int i = 1; i < n * m; i++) g[i] = (g[i - 1] * x + y) % z;
  for (int i = 0; i < n; i++) {
    q q;
    for (int j = 0; j < m; j++) {
      int x = g[i * m + j];
      while (!q.empty() && x < get<0>(q.back()))
        q.pop_back();
      q.push_back({x, j});
      while (!q.empty() && get<1>(q.front()) <= j - b)
        q.pop_front();
      if (j >= b - 1) c[i][j - b + 1] = get<0>(q.front());
    }
  }
  ll s = 0;
  for (int j = 0; j <= m - b; j++) {
    q q;
    for (int i = 0; i < n; i++) {
      int x = c[i][j];
      while (!q.empty() && x < get<0>(q.back()))
        q.pop_back();
      q.push_back({x, i});
      while (!q.empty() && get<1>(q.front()) <= i - a)
        q.pop_front();
      if (i >= a - 1) s += get<0>(q.front());
    }
  }
  cout << s << "\n";
}
