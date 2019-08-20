// https://codeforces.com/contest/1204/problem/D1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vi a(n), b(n);
  b[0] = s[0] == '0';
  a[0] = 1;
  for (int i = 1; i < n; i++)
    if (s[i] == '0') {
      b[i] = b[i - 1] + 1;
      a[i] = max(b[i], a[i - 1] + (b[i] == 0));
    } else {
      b[i] = b[i - 1];
      a[i] = a[i - 1] + 1;
    }
  vi c(n);
  c[n - 1] = a[n - 1] - b[n - 1];
  for (int i = n - 2; i >= 0; i--)
    c[i] = min(c[i + 1], a[i] - b[i]);
  for (int i = 1; i < n; i++)
    if (c[i] != c[i - 1])
      s[i] = '0';
  if (c[0] && s[0] == '1') s[0] = '0';
  cout << s << "\n";
}
