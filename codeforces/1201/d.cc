//https://codeforces.com/contest/1201/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ii = tuple<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vvi a(n);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    a[u].push_back(v);
  }
  for (int i = 0; i < n; i++)
    sort(a[i].begin(), a[i].end());
  while (n && a[n - 1].empty()) n--;
  if (n <= 0) {
    cout << 0 << endl;
    return 0;
  }
  vi b(q);
  for (int i = 0; i < q; i++) {
    cin >> b[i];
    b[i]--;
  }
  sort(b.begin(), b.end());
  vvii d(n + 1, vii(4));
  d[0] = vii(4, {0, 0});
  for (int i = 1; i < n; i++) {
    vi p(4);
    if (a[i - 1].size() == 0) {
      for (int j = 0; j < 4; j++) {
        if (i == 1) d[i][j] = {b[0] + 1, b[0]};
        else {
          ll x, y;
          tie(x, y) = d[i - 1][j];
          d[i][j] = {x + 1, y};
        }
      }
    } else {
      int l = a[i - 1].front(), r = a[i - 1].back();
      vi::iterator it[4];
      it[0] = lower_bound(b.begin(), b.end(), l);
      it[1] = lower_bound(b.begin(), b.end(), r);
      it[2] = it[0];
      it[3] = it[1];
      if (it[0] == b.end()) it[0]--, it[2]--;
      else if (it[0] != b.begin()) it[2]--;
      if (it[1] == b.end()) it[1]--, it[3]--;
      else if (it[1] != b.begin()) it[1]--;
      ll e[] = {ll(n) * m * 3, ll(n) * m * 3, ll(n) * m * 3, ll(n) * m * 3};
      for (ii z : d[i - 1]) {
        ll x, y;
        tie(x, y) = z;
        ll d1, d2;
        if (l == r) {
          d1 = d2 = abs(y - r);
        } else if (y >= l && y <= r) {
          d1 = (r - y) * 2 + y - l;
          d2 = (y - l) * 2 + r - y;
        } else if (y >= l) {
          d1 = y - l;
          d2 = (y - l) * 2 - (y - r);
        } else {
          d1 = (r - y) * 2 - (l - y);
          d2 = r - y;
        }
        e[0] = min(e[0], x + d1 + abs(l - *(it[0])));
        e[1] = min(e[1], x + d2 + abs(r - *(it[1])));
        e[2] = min(e[2], x + d1 + abs(l - *(it[2])));
        e[3] = min(e[3], x + d2 + abs(r - *(it[3])));
      }
      for (int j = 0; j < 4; j++) {
        ll x, y;
        tie(x, y) = d[i - 1][j];
        d[i][j] = {e[j] + 1, *(it[j])};
      }
    }
  }
  ll M = ll(n) * m * 3;
  int l = a[n - 1].front(), r = a[n - 1].back();
  for (int i = 0; i < 4; i++) {
    ll x, y, z;
    tie(x, y) = d[n - 1][i];
    if (y >= l && y <= r) {
      ll d1 = min(r - y, y - l);
      ll d2 = max(r - y, y - l);
      z = d1 * 2 + d2;
    } else if (y >= l) {
      z = y - l;
    } else {
      z = r - y;
    }
    M = min(M, x + z);
  }
  cout << M << "\n";
}
