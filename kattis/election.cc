// https://open.kattis.com/problems/election
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 50;
ll binom[N + 1][N + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  binom[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    binom[i][0] = 1;
    binom[i][i] = 1;
    for (int j = 1; j < i; j++)
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
  }
  int t;
  cin >> t;
  while (t--) {
    int n, v1, v2, w;
    cin >> n >> v1 >> v2 >> w;
    if (v2 * 2 >= n) cout << "RECOUNT!\n";
    else if (v1 * 2 > n)
      cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
    else {
      int need = n / 2 + 1 - v1;
      int total = n - v1 - v2;
      ll sum = 0;
      for (int i = need; i <= total; i++) sum += binom[total][i];
      ll tsum = 1LL << total;
      if (sum * 100 > w * tsum)
        cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
      else
        cout << "PATIENCE, EVERYONE!\n";
    }
  }
}
