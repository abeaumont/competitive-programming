// https://atcoder.jp/contests/arc118/tasks/arc118_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll k, n, m, sum = 0;
  cin >> k >> n >> m;
  vi a(k);
  vector<pair<ll, ll>> b(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    ll mod = (a[i] * m) % n;
    sum += mod;
    b[i] = {mod, i};
  }
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < k; i++) {
    if (!sum) break;
    b[i].first -= n;
    sum -= n;
  }
  assert(!sum);
  vi ans(k);
  for (int i = 0; i < k; i++) {
    int j = b[i].second;
    ans[j] = a[j] * m - b[i].first;
    ans[j] /= n;
  }
  for (int i = 0; i < k; i++) cout << ans[i] << " \n"[i == k - 1];
}
