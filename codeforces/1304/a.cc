// https://codeforces.com/contest/1304/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, x, y, a, b;
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    if ((y-x) % (a+b)) cout << -1;
    else cout << (y-x)/(a+b);
    cout << '\n';
  }
}
