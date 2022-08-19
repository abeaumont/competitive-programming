// https://open.kattis.com/problems/kinversions
#include <bits/stdc++.h>

using namespace std;
using cd = complex<double>;
const double pi = acos(-1);

vector<cd> fft(vector<cd> a, int d = 1) {
  int n = a.size();
  vector<cd> r(n);
  for (int k = 0; k < n; k++) {
    int b = 0;
    for (int z = 1; z < n; z *= 2) {
      b *= 2;
      if (k & z) b++;
    }
    r[b] = a[k];
  }
  for (int m = 2; m <= n; m *= 2) {
    cd wm = exp(cd{0, d * 2 * pi / m});
    for (int k = 0; k < n; k += m) {
      cd w = 1;
      for (int j = 0; j < m / 2; j++) {
        cd u = r[k + j];
        cd t = w * r[k + j + m / 2];
        r[k + j] = u + t;
        r[k + j + m / 2] = u - t;
        w = w * wm;
      }
    }
  }
  if (d == -1) {
    for (int i = 0; i < n; i++) r[i] /= n;
  }
  return r;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  int bs = 0;
  while ((1 << bs) < 2 * n - 1) bs++;
  int k = 1 << bs;
  vector<cd> a(k), b(k);
  for (int i = 0; i < n; i++)
    if (s[i] == 'A') a[i] = 1;
    else
      b[i] = 1;
  reverse(b.begin(), b.begin() + n);
  auto ta = fft(a);
  auto tb = fft(b);
  vector<cd> tp(k);
  for (int i = 0; i < k; i++) tp[i] = tb[i] * ta[i];
  auto p = fft(tp, -1);
  for (int i = 1; i < n; i++) cout << int(p[n + i - 1].real() + 0.5) << '\n';
}
