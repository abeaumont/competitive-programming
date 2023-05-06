// https://cses.fi/problemset/task/1717
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  if (n <= 2) {
    cout << n - 1 << '\n';
    return 0;
  }
  ll a = 0, b = 1, c;
  for (ll i = 3; i <= n; i++) {
    c = (i - 1) * (a + b) % M;
    a = b;
    b = c;
  }
  cout << c << '\n';
}
