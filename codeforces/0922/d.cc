// https://codeforces.com/contest/922/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<string> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  sort(t.begin(), t.end(), [&](string &i, string &j) -> bool {
    ll si = 0, hi = 0, sj = 0, hj = 0;
    for (char c : i) if (c == 's') si++; else hi++;
    for (char c : j) if (c == 's') sj++; else hj++;
    if (!si && !sj) return i.size() < j.size();
    if (!hi && !hj) return i.size() < j.size();
    if (!si) return 0;
    if (!sj) return 1;
    if (!hi) return 1;
    if (!hj) return 0;
    return si*hj > sj*hi;
  });
  ll s = 0, sum = 0;
  for (int i = 0; i < n; i++)
    for (char c : t[i])
      if (c == 's') s++;
      else sum += s;
  cout << sum << '\n';
}
