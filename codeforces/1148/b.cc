// https://codeforces.com/contest/1148/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vi a(n), b(m);
  if (n <= k || m <= k) {
    cout << "-1\n";
    return 0;
  }
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] += ta;
  }
  for (ll i = 0; i < m; i++)
    cin >> b[i];
  ll M = 0, j = 0;
  for (ll i = 0; i <= k; i++) {
    while (j < m && a[i] > b[j]) j++;
    if (j + k - i >= m || a[i] > b[j]) {
      M = -1;
      break;
    }
    M = max(M, b[j + k - i] + tb);
  }
  cout << M << "\n";
}
