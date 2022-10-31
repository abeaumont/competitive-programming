// https://open.kattis.com/problems/incognito
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string a, b;
    map<string, int> m;
    while (n--) {
      cin >> a >> b;
      m[b]++;
    }
    int ans = 1;
    for (auto &[x, c] : m) ans *= c + 1;
    cout << ans - 1 << '\n';
  }
}
