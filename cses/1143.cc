// https://cses.fi/problemset/task/1143/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k = 1, n, m, x;
  cin >> n >> m;
  while (k < n) k *= 2;
  vector<int> a(2 * k, 2e9);
  for (int i = 0; i < n; i++) cin >> a[k + i];
  for (int i = k - 1; i > 0; i--) a[i] = max(a[2 * i], a[2 * i + 1]);
  for (int i = 0; i < m; i++) {
    cin >> x;
    int r = 0, j = 1;
    while (j < k) j *= 2, j += (a[j] < x);
    if (j < k + n && a[j] >= x) {
      r = j - k + 1;
      a[j] -= x;
      for (j /= 2; j > 0; j /= 2) a[j] = max(a[2 * j], a[2 * j + 1]);
    }
    cout << r << " \n"[i == m - 1];
  }
}
