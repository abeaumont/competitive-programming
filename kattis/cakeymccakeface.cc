// https://open.kattis.com/problems/cakeymccakeface
#include <bits/stdc++.h>

using namespace std;
const int N = 2000;
int x[N], y[N];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  map<int, int> c;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (x[i] <= y[j]) c[y[j] - x[i]]++;
  int mx = 0, ans;
  for (auto [a, b] : c)
    if (b > mx) ans = a, mx = b;
  cout << ans << '\n';
}
