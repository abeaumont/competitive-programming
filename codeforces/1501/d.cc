// https://codeforces.com/contest/1501/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m), ai(2 * max(n, m));
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--, ai[a[i]] = i;
  for (int i = 0; i < m; i++) cin >> b[i], b[i]--;
  vector<vector<int>> pairs(2 * max(n, m));
  for (int i = 0; i < n; i++) pairs[a[i]].push_back(i);
  for (int i = 0; i < m; i++) pairs[b[i]].push_back(i);
  vector<int> gs(m, -1), gsi(m, -1);
  for (int i = 0, x = 0; gs[x] < 0; i++, x = (x + n) % m) gs[x] = i;
  for (int i = 0; i < m; i++)
    if (gs[i] >= 0) gsi[gs[i]] = i;
  vector<ll> xs;
  for (int i = 0; i < 2 * max(n, m); i++)
    if (pairs[i].size() == 2) {
      ll mod = (pairs[i][1] - pairs[i][0]) % m;
      if (mod < 0) mod += m;
      if (gs[mod] >= 0) xs.push_back(gs[mod] * n + ai[i]);
    }
  sort(xs.begin(), xs.end());
  ll p1 = lcm(n, m), p2 = p1 - xs.size(), r = k % p2;
  ll ans = k / p2 * p1;
  if (r == 0) ans -= p1, r = p2;
  for (ll x : xs)
    if (x < r) r++;
    else
      break;
  ans += r;
  cout << ans << '\n';
}
