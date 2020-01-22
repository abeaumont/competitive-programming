// https://open.kattis.com/problems/subseqhard
#include <bits/stdc++.h>

using namespace std;
using mii = unordered_map<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int s = 0, c = 0, x;
    mii m;
    m[0] = 1;
    while (n--) {
      cin >> x;
      s += x;
      c += m.count(s-47) ? m[s-47] : 0;
      m[s]++;
    }
    cout << c << '\n';
  }
}
