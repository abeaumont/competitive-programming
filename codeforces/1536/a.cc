// https://codeforces.com/contest/1536/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    set<int> b;
    for (int i = 0; i < n; i++) cin >> a[i], b.insert(a[i]);
    for (int i = 1; i < min(301, int(a.size())); i++)
      for (int j = 0; j < i; j++) {
        int x = abs(a[i] - a[j]);
        if (!b.count(x)) b.insert(x), a.push_back(x);
      }
    if (a.size() > 300) cout << "NO\n";
    else {
      cout << "YES\n";
      cout << a.size() << '\n';
      for (int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i == a.size() - 1];
    }
  }
}
