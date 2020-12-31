// https://open.kattis.com/problems/excursion
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  vvi a(n, vi(2));
  for (int i = n - 1; i >= 0; i--) {
    int k = s[i] - '0';
    if (k < 2) a[i][k]++;
    if (i < n - 1) a[i][0] += a[i + 1][0], a[i][1] += a[i + 1][1];
  }
  ll c = 0;
  for (int i = 0; i < n; i++) {
    int k = s[i] - '0';
    if (k == 1) c += a[i][0];
    else if (k == 2)
      c += a[i][0] + a[i][1];
  }
  cout << c << '\n';
}
