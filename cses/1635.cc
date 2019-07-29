#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n), d(x + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  d[0] = 1;
  for (int i = 1; i <= x; i++)
    for (int c : a)
      if (c <= i) d[i] = (d[i] + d[i - c]) % 1000000007;
  cout << d[x] << "\n";
}
