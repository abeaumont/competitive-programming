// https://cses.fi/problemset/task/1713/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  bitset<N + 1> p;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 4; i <= N; i += 2) p[i] = 0;
  for (ll i = 3; i <= N; i += 2)
    if (p[i])
      for (ll j = i * i; j <= N; j += 2 * i)
        p[j] = 0;
  vector<int> a;
  for (int i = 0; i <= N; i++)
    if (p[i])
      a.push_back(i);
  int n, x, s, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s = 1;
    for (int y : a) {
      c = 1;
      while (!(x % y)) {
        x /= y;
        c++;
      }
      s *= c;
      if (y * y >= x) {
        s *= 1 + (x > 1);
        break;
      }
    }
    cout << s << "\n";
  }
}
