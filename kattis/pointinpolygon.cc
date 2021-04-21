// https://open.kattis.com/problems/pointinpolygon
#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
  P(int x = 0, int y = 0) : x(x), y(y) {}
  P operator-(P p) { return P(x - p.x, y - p.y); }
  int operator*(P p) { return x * p.x + y * p.y; }
  int operator^(P p) { return x * p.y - y * p.x; }
  friend ostream &operator<<(ostream &os, P p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, m, x, y;
    cin >> n;
    if (!n) break;
    vector<P> ps(n);
    for (int i = 0; i < n; i++) cin >> x >> y, ps[i] = P(x, y);
    cin >> m;
    while (m--) {
      cin >> x >> y;
      P a(x, y);
      string ans = "";
      bool c = 0;
      for (int i = 0; i < n; i++) {
        P p = ps[i], q = ps[(i + 1) % n];
        if (((p - a) ^ (q - a)) == 0 && ((p - a) * (q - a) <= 0)) {
          ans = "on";
          break;
        }
        c ^= ((a.y < p.y) - (a.y < q.y)) * ((p - a) ^ (q - a)) > 0;
      }
      if (ans.empty()) ans = c ? "in" : "out";
      cout << ans << '\n';
    }
  }
}
