// https://cses.fi/problemset/task/1744
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int a, b;
  cin >> a >> b;
  vvi x(a + 1, vi(b + 1, 1e9));
  for (int i = 1; i <= min(a, b); i++) x[i][i] = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= i / 2; k++)
        x[i][j] = min(x[i][j], x[k][j] + x[i - k][j] + 1);
      for (int k = 1; k <= j / 2; k++)
        x[i][j] = min(x[i][j], x[i][k] + x[i][j - k] + 1);
    }
  cout << x[a][b] << "\n";
}
