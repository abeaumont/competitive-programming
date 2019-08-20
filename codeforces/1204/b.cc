// https://codeforces.com/contest/1204/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  ll s = 0, t = 0, a = 1, b = 1;
  for (int i = 1; i <= n; i++) {
    s += a, t += b;
    if (i < l) a *= 2;
    else a = 1;
    if (i < r) b *= 2;
  }
  cout << s << " " << t << "\n";
}
