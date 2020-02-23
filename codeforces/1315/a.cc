// https://codeforces.com/contest/1315/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t, a, b, x, y;
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> x >> y;
    cout << max(max(x, a-x-1)*b,max(y,b-y-1)*a) << '\n';
  }
}
