// https://codeforces.com/contest/1407/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using si = unordered_multiset<int>;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    si a(n);
    vi b;
    int x, m = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      m = max(m, x);
      a.insert(x);
    }
    int g = m;
    b.push_back(m);
    a.erase(a.find(m));
    while (!a.empty()) {
      int m = 0, k;
      for (int x : a) {
        int gg = gcd(g, x);
        if (gg > m) {
          m = gg;
          k = x;
        }
      }
      g = m;
      b.push_back(k);
      a.erase(a.find(k));
    }
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
  }
}
