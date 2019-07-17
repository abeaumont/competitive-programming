// https://codeforces.com/contest/1195/problem/D1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll M = 998244353;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n;
  vvi d (n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    while (x) {
      d[i].push_back(x % 10);
      x /= 10;
    }
  }
  ll s = 0;
  for (int i = 0; i < n; i++) {
    ll m = 1;
    for (int j = 0; j < d[i].size(); j++) {
      ll x = (n * d[i][j]) % M;
      x = (x * m) % M;
      s = (s + x) % M;
      if (s < 0) s += M;
      m = (m * 10) % M;
      x = (n * d[i][j]) % M;
      x = (x * m) % M;
      s = (s + x) % M;
      if (s < 0) s += M;
      m = (m * 10) % M;
    }
  }
  cout << s << "\n";
}
