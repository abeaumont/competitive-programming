// https://codeforces.com/contest/1199/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = max(0, i - x); j < i; j++)
      if (a[j] < a[i]) {
        ok = false;
        break;
      }
    for (int j = i + 1; j < min(i + y + 1, n); j++)
      if (a[j] < a[i]) {
        ok = false;
        break;
    }
    if (ok) {
      cout << i + 1 << endl;
      break;
    }
  }
}
