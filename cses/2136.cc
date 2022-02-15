// https://cses.fi/problemset/task/2136
#include <bits/stdc++.h>

using namespace std;
const int N = 2e4;
int xs[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < k; j++) xs[i] = (xs[i] << 1) + s[j] - '0';
  }
  int ans = k + 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = min(ans, __builtin_popcount(xs[i] ^ xs[j]));
  cout << ans << '\n';
}
