// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146183
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = tuple<ll, ll>;
using vii = vector<ii>;
using si =  unordered_set<ll>;

const ll MAX = 1000000001;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n;
    vii a(n);
    si s;
    for (int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        a[i] = { u, v };
    }
    ll c = 1;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        ll x, y, x1, y1, x2, y2;
        tie(x1, y1) = a[i];
        tie(x2, y2) = a[j];
        if (x1 == x2 || y1 == y2) continue;
        if (x2 > x1 && y2 > y1) continue;
        if (x1 > x2 && y1 > y2) continue;
        if (x1 > x2) x = x1 - x2, y = y2 - y1;
        else x = x2 - x1, y = y1 - y2;
        ll g = __gcd(x, y);
        x /= g, y /= g;
        ll p = x * MAX + y;
        if (!s.count(p)) {
          c++;
          s.insert(p);
        }
      }
    cout << "Case #" << T << ": " << c << "\n";
  }
}
