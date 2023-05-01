// https://cses.fi/problemset/task/2185
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll x[20];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> x[i];
  for (int i = 1; i < (1 << k); i++) {
    ll p = 1;
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        if (n / p < x[j]) {
          p = 0;
          break;
        }
        p *= x[j];
      }
    }
    if (p) {
      p = n / p;
      if (!__builtin_parity(i)) p = -p;
      ans += p;
    }
  }
  cout << ans << '\n';
}
