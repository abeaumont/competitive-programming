// https://codeforces.com/contest/1305/problem/A
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
  ll n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n-1];
  }
}
