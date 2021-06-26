// https://cses.fi/problemset/task/2220/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool f(vector<int> &d) {
  bool mx = 0;
  for (int i = 0; i < d.size() - 1; i++) {
    if (mx == 1) d[i + 1] = 9;
    if (d[i] == d[i + 1]) {
      int j = i + 1;
      d[j]--;
      if (d[j] < 0) {
        while (d[j] < 0) {
          d[j] = 9;
          d[--j]--;
        }
        return 0;
      }
      mx = 1;
    }
  }
  return 1;
}

ll g(vector<int> &d) {
  ll s = 0, b = 1, p = -1;
  for (int i = 0; i < d.size() - 1; i++) {
    if (d[i] > d[i + 1]) s -= b;
    s += (d[i] + (i != d.size() - 2)) * b;
    b *= 9;
  }
  return s;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll a, b;
  cin >> a >> b;
  if (b == 0) {
    cout << "1\n";
    return 0;
  }

  vector<int> d;
  while (b > 0) d.push_back(b % 10), b /= 10;
  reverse(d.begin(), d.end());
  while (!f(d))
    ;
  reverse(d.begin(), d.end());
  d.push_back(9);
  ll ans = g(d);
  if (a <= 1) {
    cout << ans + (a == 0) << '\n';
    return 0;
  }
  d.clear();
  a--;
  while (a > 0) d.push_back(a % 10), a /= 10;
  reverse(d.begin(), d.end());
  while (!f(d))
    ;
  reverse(d.begin(), d.end());
  d.push_back(9);
  ans -= g(d);
  cout << ans << '\n';
}
