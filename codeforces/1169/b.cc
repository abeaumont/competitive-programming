// https://codeforces.com/contest/1169/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ii = tuple<int, int>;
using vii = vector<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p, q, u, v;
  cin >> n >> m;
  vii a(m);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    a[i] = { u, v };
  }
  bool ok = true;
  vii b;
  tie(p, q) = a[0];
  for (int i = 1; i < m; i++) {
    tie(u, v) = a[i];
    if (p != u && q != u && p != v && q != v) {
      b.push_back({p, u});
      b.push_back({p, v});
      b.push_back({q, u});
      b.push_back({q, v});
      break;
    }
  }
  if (!b.empty())
    for (int i = 0; i < m; i++) {
      tie (u, v) = a[i];
      int j = 0;
      while (j < b.size()) {
        tie(p, q) = b[j];
        if (u != p && u != q && v != p && v != q) {
          swap(b[j], b.back());
          b.pop_back();
        } else j++;
      }
      if (b.empty()) {
        ok = false;
        break;
      }
    }
  cout << (ok ? "YES\n" : "NO\n");
}
