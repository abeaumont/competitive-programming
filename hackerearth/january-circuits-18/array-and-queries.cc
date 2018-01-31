// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/array-and-queries-d544bfb2/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int pow(int x, int n) {
  int r = 1;
  for (int i = 0; i < n; i++) r *= x;
  return r;
}

int main() {
  int n, q;
  cin >> n >> q;
  n = pow(2, n);
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < q; i++) {
    int t, l, r, m, v, k;
    cin >> t;
    switch (t) {
    case 1:
      cin >> l >> r;
      m = a[l];
      for (int j = l + 1; j <= r; j++) m = max(m, a[j]);
      cout << m << endl;
      break;
    case 2:
      cin >> l >> r >> v;
      for (int j = l; j <= r; j++) a[j] = v;
      break;
    case 3:
      cin >> k;
      vi b(n);
      for (int i = 0; i < n; i++) b[i ^ k] = a[i];
      a = b;
    }
  }
}
