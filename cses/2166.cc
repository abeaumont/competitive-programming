// https://cses.fi/problemset/task/2166/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = (1LL << 60), N = 2e5;
ll x[N];
pair<ll, ll> t[1 << 19];

void add(int a, int b, int k, int x, int y, ll v) {
  if (b < x || a > y) return;
  if (a <= x && y <= b) {
    t[k].second += v;
    return;
  }
  if (t[k].second) {
    t[2 * k].second += t[k].second;
    t[2 * k + 1].second += t[k].second;
  }
  int d = (x + y) / 2;
  add(a, b, k * 2, x, d, v);
  add(a, b, k * 2 + 1, d + 1, y, v);
  t[k] = {max(t[2 * k].first + t[2 * k].second,
              t[2 * k + 1].first + t[2 * k + 1].second),
          0};
}

ll mx(int a, int b, int k, int x, int y) {
  if (b < x || a > y) return -INF;
  if (a <= x && y <= b) return t[k].first + t[k].second;
  if (t[k].second) {
    t[2 * k].second += t[k].second;
    t[2 * k + 1].second += t[k].second;
  }
  int d = (x + y) / 2;
  ll r = max(mx(a, b, k * 2, x, d), mx(a, b, k * 2 + 1, d + 1, y));
  t[k] = {max(t[2 * k].first + t[2 * k].second,
              t[2 * k + 1].first + t[2 * k + 1].second),
          0};
  return r;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, k = 1, q, p, a, b;
  cin >> n >> q;
  while (k < n) k *= 2;
  fill(t, t + 2 * k, make_pair(-INF, 0));
  for (int i = 0; i < n; i++)
    cin >> x[i], t[k + i] = {x[i] + (i ? t[k + i - 1].first : 0), 0};
  for (int i = k - 1; i; i--)
    t[i] = {max(t[2 * i].first, t[2 * i + 1].first), 0};
  while (q--) {
    cin >> p >> a >> b;
    if (p == 1) {
      ll d = b - x[a - 1];
      x[a - 1] += d;
      add(a - 1, n - 1, 1, 0, k - 1, d);
    } else {
      ll p = 0;
      if (a > 1) p = mx(a - 2, a - 2, 1, 0, k - 1);
      cout << max(0LL, mx(a - 1, b - 1, 1, 0, k - 1) - p) << '\n';
    }
  }
}
