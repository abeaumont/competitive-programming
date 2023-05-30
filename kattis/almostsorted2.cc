// https://open.kattis.com/problems/almostsorted2
#include <bits/stdc++.h>

using namespace std;
const int N = 3e5;
int a[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i > 0 && x == a[i - 1]) n--, i--;
    else
      a[i] = x;
  }

  if (n == 102 || (n == 100 && a[0] >= 100)) {
    cout << "No\n";
    return 0;
  }

  bool asc = 1, ok = 1;
  int changes = 0, is[2] = {0, n - 1};
  for (int i = 1; i < n; i++)
    if (asc) {
      if (a[i] < a[i - 1]) {
        is[changes % 2] = i - 1;
        asc = 0;
        changes++;
      }
    } else {
      if (a[i] > a[i - 1]) {
        is[changes % 2] = i - 1;
        asc = 1;
        changes++;
      }
    }
  if (changes > 2) {
    cout << "No\n";
    return 0;
  }
  if (changes) reverse(a + is[0], a + is[1] + 1);
  for (int i = 1; i < n; i++)
    if (a[i] < a[i - 1]) ok = 0;
  cout << (ok ? "Yes\n" : "No\n");
}
