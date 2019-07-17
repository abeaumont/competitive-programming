// https://codeforces.com/contest/1195/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vi a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vvi d(n, vi(3));
  d[0][0] = a[0];
  d[0][1] = b[0];
  d[0][2] = 0;
  for (int i = 1; i < n; i++) {
    d[i][0] = max(d[i - 1][1], d[i - 1][2]) + a[i];
    d[i][1] = max(d[i - 1][0], d[i - 1][2]) + b[i];
    d[i][2] = max(d[i - 1][0], d[i - 1][1]);
  }
  cout << max(d[n-1][0], max(d[n-1][1], d[n-1][2])) << "\n";
}
