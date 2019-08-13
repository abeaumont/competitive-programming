// https://cses.fi/problemset/task/1647
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vi x;
vvi y;

void f() {
  y.push_back(vi(n));
  for (int i = 0; i < n; i++) y[0][i] = x[i];
  for (int i = 1, k = 2; k <= n; i++, k *= 2) {
    y.push_back(vi(n - k + 1));
    for (int j = 0; j <= n - k; j++)
      y[i][j] = min(y[i - 1][j], y[i - 1][j + k/2]);
  }
}

int m(int a, int b) {
  int d = b - a + 1;
  int i = 0, k = 1;
  for (; k * 2 <= d; i++, k *= 2);
  return min(y[i][a - 1], y[i][b - k]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, a, b;
  cin >> n >> q;
  x = vi(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  f();
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    cout << m(a, b) << "\n";
  }
}
