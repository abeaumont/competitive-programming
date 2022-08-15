// https://atcoder.jp/contests/mujin-pc-2017/tasks/mujin_pc_2017_a
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll j = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] < 2 * (i + 1) - 2 * j - 1) {
      b[j] = i + 1 - j;
      j++;
    }
  }
  for (; j < n; j++) b[j] = n - j;
  ll ans = 1;
  for (ll x : b) (ans *= x) %= M;
  cout << ans << '\n';
}
