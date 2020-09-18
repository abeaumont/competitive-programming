// https://codeforces.com/contest/1407/problem/C
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int n;
  cin >> n;
  int k = 0;
  vi a(n), b(n);
  for (int i = 1; i < n; i++) {
    int r1, r2;
    cout << "? " << k + 1 << ' ' << i + 1 << endl;
    cin >> r1;
    assert(r1 >= 0);
    cout << "? " << i + 1 << ' ' << k + 1 << endl;
    cin >> r2;
    assert(r2 >= 0);
    if (r1 > r2) {
      a[r1 - 1] = 1;
      b[k] = r1;
      k = i;
    } else {
      a[r2 - 1] = 1;
      b[i] = r2;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      b[k] = i + 1;
      break;
    }
  }
  cout << '!';
  for (int x : b) cout << ' ' << x;
  cout << endl;
}
