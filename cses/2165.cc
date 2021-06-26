// https://cses.fi/problemset/task/2165
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;

vii ans;

void f(int n, int l, int m, int r) {
  if (n <= 0) return;
  f(n - 1, l, r, m);
  ans.push_back({l, r});
  f(n - 1, m, l, r);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  f(n, 1, 2, 3);
  cout << ans.size() << '\n';
  for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}
