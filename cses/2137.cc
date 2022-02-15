// https://cses.fi/problemset/task/2137
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 3000;
ll xs[N], t[N * N], ans;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; i += 64) {
    for (int j = 0; i + j < n && j < 64; j++) {
      cin >> s;
      for (int k = 0; k < n; k++)
        xs[k] = ((j == 0 ? 0 : xs[k]) << 1) + s[k] - '0';
    }
    for (int j = 0; j < n; j++)
      for (int k = j + 1; k < n; k++)
        t[j * n + k] += __builtin_popcountll(xs[j] & xs[k]);
  }
  for (int j = 0; j < n; j++)
    for (int k = j + 1; k < n; k++)
      ans += t[j * n + k] * (t[j * n + k] - 1) / 2;
  cout << ans << '\n';
}
