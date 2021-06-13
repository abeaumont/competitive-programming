// https://atcoder.jp/contests/arc118/tasks/arc118_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  cout << "6 10 15";
  n -= 3;
  int xs[3] = {6, 10, 15};
  int j = 0, k = 2;
  while (n--) {
    while (1) {
      ll z = xs[j] * k;
      if (z > 10000) j++, k = 2;
      bool ok = 1;
      for (int i = 0; i < j; i++)
        if (z % xs[i] == 0) {
          ok = 0;
          break;
        }
      if (ok) break;
      k++;
    }
    cout << ' ' << xs[j] * k++;
  }
  cout << '\n';
}
