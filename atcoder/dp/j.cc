// https://atcoder.jp/contests/dp/tasks/dp_j
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using iii = tuple<int, int, int>;
int a[4];

struct Hash {
  size_t operator()(const iii &x) const {
    int a, b, c;
    tie(a, b, c) = x;
    return a * 90000LL + b * 300LL + c;
  }
};

int main() {
  cin.tie(0), ios::sync_with_stdio();
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x, a[x]++;
  unordered_map<iii, double, Hash> m;
  queue<iii> q;
  iii k = {a[1], a[2], a[3]};
  m[k] = 1;
  q.push(k);
  double ans = 0;
  while (!q.empty()) {
    iii x = q.front();
    int a, b, c, d;
    tie(b, c, d) = x;
    if (!(b + c + d)) break;
    q.pop();
    int sum = b + c + d;
    a = n - sum;
    ans += m[x] * n / sum;
    double v = m[x];
    if (b) {
      iii y = {b - 1, c, d};
      if (!m.count(y)) q.push(y);
      m[y] += v * b / sum;
    }
    if (c) {
      iii y = {b + 1, c - 1, d};
      if (!m.count(y)) q.push(y);
      m[y] += v * c / sum;
    }
    if (d) {
      iii y = {b, c + 1, d - 1};
      if (!m.count(y)) q.push(y);
      m[y] += v * d / sum;
    }
  }
  cout << setprecision(20) << ans << '\n';
}
