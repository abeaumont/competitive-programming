// https://cses.fi/problemset/task/1640/
#include <bits/stdc++.h>

using namespace std;
using ii=tuple<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, k;
  cin >> n >> x;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> k;
    a[i] = {k, i};
  }
  sort(a.begin(), a.end());
  int i = 0, j = n - 1;
  while (j > i) {
    int k = get<0>(a[i]) + get<0>(a[j]);
    if (k == x) {
      cout << get<1>(a[i]) + 1 << " " << get<1>(a[j]) + 1 << "\n";
      return 0;
    }
    if (k < x) i++;
    else j--;
  }
  cout << "IMPOSSIBLE\n";
}
