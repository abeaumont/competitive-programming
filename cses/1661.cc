// https://cses.fi/problemset/stats/1661/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using mii = map<ll, vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vi a(n), b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }
  mii m;
  for (int i = 0; i <= n; i++)
    m[b[i]].push_back(i);
  ll s = 0;
  for (int i = 1; i <= n; i++) {
    vi &c = m[b[i] - x];
    s += lower_bound(c.begin(), c.end(), i) - c.begin();
  }
  cout << s << "\n";
}
