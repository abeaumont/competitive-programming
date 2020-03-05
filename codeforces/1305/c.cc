// https://codeforces.com/contest/1305/problem/C
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
  ll n, m;
  cin >> n >> m;;
  vi a(n);
  ll p = 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n > 2000) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      ll d = a[i] > a[j] ? a[i] - a[j] : a[j] - a[i];
      (d %= m);
      (p *= d) %= m;
    }
  cout << p << '\n';
}
