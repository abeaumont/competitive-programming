// https://cses.fi/problemset/task/1732/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int x = 0, y = 0, n;
  string s;
  cin >> s;
  n = s.size();
  vi a(n), r;
  for (int i=1; i<n; i++) {
    a[i] = max(0, min(a[i-x], y-i));
    while (a[i]+i < n && s[a[i]] == s[a[i]+i]) a[i]++;
    if (a[i]+i > y) x=i, y=a[i]+i;
    if (a[i]+i == n) r.push_back(a[i]);
  }
  for (int i = r.size() - 1; i >= 0; i--) cout << r[i] << " \n"[!i];
}
