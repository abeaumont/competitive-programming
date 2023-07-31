// https://open.kattis.com/problems/aliens
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 4e4, a = 911382323, b = 972663749;
ll p[N], h[N + 1];
int m, n;
string s;

int solve(int l) {
  if (l > n) return -1;
  map<ll, int> count;
  int ans = -1;
  for (int i = 0; i <= n - l; i++) {
    ll hash = (h[i + l] - h[i] * p[l]) % b;
    if (hash < 0) hash += b;
    count[hash] += 1;
    if (count[hash] >= m) ans = i;
  }
  return ans;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  p[0] = 1;
  for (int i = 1; i < N; i++) p[i] = (p[i - 1] * a) % b;
  while (1) {
    cin >> m;
    if (!m) break;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) h[i + 1] = (h[i] * a + s[i]) % b;
    int x = 0;
    for (int b = n; b >= 1; b /= 2)
      while (solve(x + b) >= 0) x += b;
    if (x) cout << x << ' ' << solve(x) << '\n';
    else
      cout << "none\n";
  }
}
