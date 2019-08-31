// https://cses.fi/problemset/task/1652/
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, w, x, y, z;
  cin >> n >> q;
  vvi a(n + 1, vi(n + 1));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++)
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[j - 1] == '*');
  }
  while (q--)
    cin >> w >> x >> y >> z, cout << a[y][z] - a[y][x - 1] - a[w - 1][z] + a[w - 1][x - 1] << "\n";
}
