// https://open.kattis.com/problems/vacuumba
#include <bits/stdc++.h>

using namespace std;
using pt = complex<double>;

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    pt p = {0,0};
    double a = M_PI/2;
    for (int i = 0; i < m; i++) {
      double d, l;
      cin >> d >> l;
      a += (d * M_PI/180);
      p += polar(l, a);
    }
    cout << setprecision(10) << p.real() << ' ' << p.imag() << '\n';
  }
}
