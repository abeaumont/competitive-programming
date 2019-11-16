// https://codeforces.com/contest/1253/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi a(n), b(n), r(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (i) r[i] += r[i - 1];
    b[i] = a[i];
    if (i >= m) b[i] += b[i - m];
    r[i] += b[i];
  }
  for (int i = 0; i < n; i++)
    cout << r[i] << " \n"[i == n - 1];
}
