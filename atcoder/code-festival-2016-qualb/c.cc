// https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int w, h;
  cin >> w >> h;
  ll p, q;
  vector<tuple<ll, int, bool>> a(w + h);
  for (int i = 0; i < w; i++) {
    cin >> p;
    a[i] = {p, i, 0};
  }
  for (int i = 0; i < h; i++) {
    cin >> q;
    a[i + w] = {q, i, 1};
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (auto [p, i, d] : a)
    if (d) {
      ans += p * (w + 1);
      h--;
    } else {
      ans += p * (h + 1);
      w--;
    }
  cout << ans << '\n';
}
