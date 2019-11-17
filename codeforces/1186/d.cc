// https://codeforces.com/contest/1186/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, s = 0;
  cin >> n;
  vector<ll> b(n);
  vector<bool> c(n);
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    b[i] = ll(ceil(x));
    c[i] = x != ceil(x);
    s += b[i];
  }
  for (int i = 0; s; i++)
    if (c[i])
      b[i]--, s--;
  for (ll x : b) cout << x << "\n";
}
