// https://codeforces.com/contest/1291/problem/A
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main () {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n);
    string s;
    cin >> s;
    int mod = 0;
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
      mod = (mod + a[i]) % 2;
    }
    while (a.size() && a.back() % 2 == 0) a.pop_back();
    if (a.size() && mod) a.pop_back();
    while (a.size() && a.back() % 2 == 0) a.pop_back();
    if (a.size())
      for (int x : a)
        cout << x;
    else cout << -1;
    cout << '\n';
  }
}
