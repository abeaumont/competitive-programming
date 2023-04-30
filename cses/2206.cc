// https://cses.fi/problemset/task/2206
#include <bits/stdc++.h>

using namespace std;
const int N = (1 << 19), INF = 1e9 + 1;
tuple<int, int, int> t[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, k = 1, o, p, x, l1, r1, l2, r2, d1, d2;
  cin >> n >> q;
  while (k < n) k *= 2;
  fill(t, t + 2 * k, make_tuple(INF, INF, 1));
  for (int i = 0; i < n; i++) cin >> x, t[k + i] = {x, x, 1};
  for (int i = k - 1; i; i--) {
    tie(l1, r1, d1) = t[2 * i];
    tie(l2, r2, d2) = t[2 * i + 1];
    t[i] = {min(l1, l2 + d2), min(r1 + d1, r2), d1 * 2};
  }
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> p >> x;
      int i = k + p - 1;
      t[i] = {x, x, 1};
      for (i /= 2; i; i /= 2) {
        tie(l1, r1, d1) = t[2 * i];
        tie(l2, r2, d2) = t[2 * i + 1];
        t[i] = {min(l1, l2 + d2), min(r1 + d1, r2), d1 * 2};
      }
    } else {
      cin >> x;
      int i = k + x - 1, mn = get<0>(t[i]), l = 1, r = 1;
      for (int b = i & 1, j = i / 2; j; b = j & 1, j /= 2)
        if (b) {
          tie(l1, r1, d1) = t[2 * j];
          mn = min(mn, r1 + l);
          l += d1;
        } else {
          tie(l1, r1, d1) = t[2 * j + 1];
          mn = min(mn, l1 + r);
          r += d1;
        }
      cout << mn << '\n';
    }
  }
}
