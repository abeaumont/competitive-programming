// https://codeforces.com/contest/1316/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      if (a[0] >= m) break;
      a[0] += a[i];
    }
    cout << min(m, a[0]) << '\n';
  }
}
