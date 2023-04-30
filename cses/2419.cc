// https://cses.fi/problemset/task/2419/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int a[N], n;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> idx(1);
  for (int i = 0, k = 0; (1 << i) < n; i++)
    if ((n - 1) & (1 << i)) {
      k += 1 << i;
      for (int j = idx.size() - 1; j >= 0; j--) idx.push_back(k - idx[j]);
    }
  int ans = 0;
  for (int k : idx) ans ^= a[k];
  cout << ans << '\n';
}
