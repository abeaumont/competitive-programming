// https://open.kattis.com/problems/aliennumbers
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 128;
ll m[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    string a, b, c, ans;
    ll x = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < b.size(); i++) m[b[i]] = i;
    for (char c : a) x = x * b.size() + m[c];
    ll k = 1;
    while (k <= x) k *= c.size();
    for (ll y = k / c.size(); y > 1; y /= c.size()) {
      ll d = x / y;
      x -= d * y;
      ans.push_back(c[d]);
    }
    ans.push_back(c[x]);
    cout << "Case #" << T << ": " << ans << '\n';
  }
}
