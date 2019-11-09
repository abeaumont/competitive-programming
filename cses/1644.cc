// https://cses.fi/problemset/task/1644/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using ii = tuple<ll, int>;
using qii = deque<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b, d;
  cin >> n >> a >> b;
  d = b - a;
  vi x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    y[i] = x[i];
    if (i) y[i] += y[i - 1];
  }
  ll s = y[a - 1];
  qii q;
  for (int i = a; i < b; i++) {
    while (!q.empty() && y[i] > get<0>(q.back())) q.pop_back();
    q.push_back({y[i], i});
  }
  ll m = -2e18;
  for (int i = a;;i++) {
    ll k = 0;
    if (!q.empty()) {
      k = get<0>(q.front());
      k -= y[i - 1];
    }
    ll r = s;
    if (k > 0) r += k;
    if (r > m) m = r;
    if (i == n) break;
    s -= x[i - a];
    s += x[i];
    while (!q.empty() && get<1>(q.front()) <= i) q.pop_front();
    if (i + d < n) {
      while (!q.empty() && y[i + d] > get<0>(q.back())) q.pop_back();
      q.push_back({y[i + d], i + d});
    }
  }
  cout << m << "\n";
}
