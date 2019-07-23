// https://cses.fi/problemset/task/1630
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vii = vector<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n;
  vii a(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a.begin(), a.end());
  ll c = 0, k = 0;
  for (ii z : a) {
    tie(x, y) = z;
    c += y - (x + k);
    k += x;
  }
  cout << c << "\n";
}
