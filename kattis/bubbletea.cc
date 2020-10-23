// https://open.kattis.com/problems/bubbletea
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, k, u, p;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  vi b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    cin >> k;
    int min;
    cin >> min, min--;
    for (int j = 1; j < k; j++) {
      cin >> u, u--;
      if (b[u] < b[min]) min = u;
    }
    a[i] += b[min];
  }
  cin >> p;
  sort(a.begin(), a.end());
  cout << max(0, (p / a[0] - 1)) << '\n';
}
