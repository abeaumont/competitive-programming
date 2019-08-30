// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(x + 1, x + 1), c(n);
  a[0] = 0;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 1; i <= x; i++)
    for (int j = 0; j < n; j++)
      if (c[j] <= i)
        a[i] = min(a[i], a[i - c[j]] + 1);
  cout << (a[x] == x + 1 ? -1 : a[x]) << "\n";
}
