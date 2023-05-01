// https://cses.fi/problemset/task/2417
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6, K = 1e5;
ll s[N + 1], t[N + 1];
vector<ll> d[N];

int main() {
  cin.tie(0), ios::sync_with_stdio();
  for (ll i = 2; i <= N; i++)
    if (!s[i])
      for (ll j = i * 2; j <= N; j += i) s[j] = i;
  ll n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    while (x > 1) {
      int f = s[x];
      if (!f) f = x;
      d[i].push_back(f);
      while (!(x % f)) x /= f;
    }
    int k = d[i].size();
    for (int j = 1; j < (1 << k); j++) {
      int p = 1;
      for (int l = 0; l < k; l++)
        if (j & (1 << l)) p *= d[i][l];
      t[p]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int k = d[i].size();
    for (int j = 1; j < (1 << k); j++) {
      int p = 1;
      for (int l = 0; l < k; l++)
        if (j & (1 << l)) p *= d[i][l];
      if (!__builtin_parity(j)) ans += t[p] - 1;
      else
        ans -= t[p] - 1;
    }
  }
  cout << (n * (n - 1) / 2) + ans / 2 << '\n';
}
