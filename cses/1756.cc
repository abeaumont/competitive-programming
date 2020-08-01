// https://cses.fi/problemset/task/1756
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v)
      swap(u, v);
    cout << u << ' ' << v << '\n';
  }
}
