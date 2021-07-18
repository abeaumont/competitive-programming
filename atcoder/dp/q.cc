// https://atcoder.jp/contests/dp/tasks/dp_q
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> h(n), a(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, ll> m;
  for (int i = 0; i < n; i++) {
    auto it = m.lower_bound(h[i]);
    ll v = 0;
    if (it != m.begin()) {
      it--;
      v = it->second;
      it++;
    }
    v += a[i];
    while (it != m.end()) {
      if (it->second > v) break;
      m.erase(it);
      it = m.lower_bound(h[i]);
    }
    m[h[i]] = v;
  }
  cout << m.rbegin()->second << '\n';
}
