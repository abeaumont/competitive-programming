// https://www.codechef.com/OCT19A/problems/MSV
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int N = 1000000;
vi d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n);
    d = vi(N+1);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = 0;
    for (int i = 0; i < n; i++) {
      int x = a[i];
      if (m < d[x]) m = d[x];
      for (int i = 1; i * i <= x; i++)
        if (!(x % i)) {
          d[i]++;
          int y = x / i;
          if (y != i) d[y]++;
        }
    }
    cout << m << "\n";
  }
}
